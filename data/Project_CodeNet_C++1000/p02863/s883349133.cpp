#include<bits/stdc++.h>
using namespace std;
int DP(int n,int t,vector<int>a,vector<int>b){
    int x=0;
    vector<vector<int>>dp(n+1,vector<int>(t,-1000000000));
    //i番目まで見てj分かけたときの美味しさの最大値
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<t;j++){
            //食べる
            if(j+a[i]<t)dp[i+1][j+a[i]]=max(dp[i][j]+b[i],dp[i+1][j+a[i]]);
            //食べない
            dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
            x=max(dp[i+1][j],x);
        }
    }
    return x;
}
int main(){
    int n,t;
    cin>>n>>t;
    int a[n],b[n];
    vector<pair<int,int>>p1(n);
    vector<pair<int,int>>p2(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        p1[i]={a[i],b[i]};
        p2[i]={b[i],a[i]};
    }
    sort(p1.begin(),p1.end());
    sort(p2.begin(),p2.end());
    vector<int>a1(n-1);
    vector<int>b1(n-1);//最も時間かかるものを除いた
    vector<int>a2(n-1);
    vector<int>b2(n-1);//最も美味しいものを除いた
    vector<int>a3(n-1);
    vector<int>b3(n-1);//2番目に時間かかるものを除いた
    vector<int>a4(n-1);
    vector<int>b4(n-1);//2番目に美味しいものを除いた
    for(int i=0;i<n-2;i++){
        a1[i]=p1[i].first;
        b1[i]=p1[i].second;
        a2[i]=p2[i].second;
        b2[i]=p2[i].first;
        a3[i]=p1[i].first;
        b3[i]=p1[i].second;
        a4[i]=p2[i].second;
        b4[i]=p2[i].first;
    }
    a1[n-2]=p1[n-2].first;
    b1[n-2]=p1[n-2].second;
    a2[n-2]=p2[n-2].second;
    b2[n-2]=p2[n-2].first;
    a3[n-2]=p1[n-1].first;
    b3[n-2]=p1[n-1].second;
    a4[n-2]=p2[n-1].second;
    b4[n-2]=p2[n-1].first;
    cout<<max({DP(n-1,t,a1,b1)+p1[n-1].second,DP(n-1,t,a2,b2)+p2[n-1].first
              ,DP(n-1,t,a3,b3)+p1[n-2].second,DP(n-1,t,a4,b4)+p2[n-2].first})<<endl;
    return 0;
}