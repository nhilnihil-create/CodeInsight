#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
#define ld long double
int main(){
    int n,m;
    cin>>n>>m;
    vector<bitset<12>> c(m);
    map<vector<int>,int> p;
    vector<int> a(m),b(m);
    rep(i,m){
        bitset<12> s(0);
        cin>>a[i]>>b[i];
        rep(j,b[i]){
            int C;    
            cin>>C;
            C--;
            //c[i].push_back(C);
            s.set(C,1);
        }
        c[i]=s;
    }
    rep(i,m){
        //cout<<c[i]<<endl;
    }
    int k=pow(2,n);
    vector<vector<int>> dp(m+1,vector<int> (k+1,1e9));
    rep(i,m+1){
    dp[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        rep(j,k){
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            bitset<12> bi(j);
            //cout<<bi<<"|"<<c[i]<<" ";
            dp[i][(bi|c[i-1]).to_ullong()] = min(dp[i][(bi|c[i-1]).to_ullong()],(min(dp[i-1][(bi|c[i-1]).to_ullong()],dp[i-1][j] + a[i-1]))); 
            //cout<<"dp["<<i<<"]["<<(bi|c[i-1]).to_ullong()<<"]="<<dp[i][(bi|c[i-1]).to_ullong()]<<endl;
        }
    }/*
    rep(i,m+1){
        rep(j,k){
            if(dp[i][j]==1e9){
                cout<<"N"<<" ";
            }
            else{
                cout<<dp[i][j]<<" ";
            }
        }
        cout<<endl;
    }*/
    if(dp[m][k-1]==1e9){
        cout<<-1<<endl;
        return 0;
    }
    cout<<dp[m][k-1]<<endl;
}