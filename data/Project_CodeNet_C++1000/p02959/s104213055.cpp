#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    long long int n;
    cin>>n;
    vector<long long int> city(n+1);
    rep(i,n+1){
        cin>>city[i];
        //cerr<<city[i]<<" ";
    }
    long long int x,ans=0;
    rep(i,n){
        cin>>x;
        if(x>city[i]){
            //次の街を倒し切ってしまうパターン
            if(x>=city[i]+city[i+1]){
                ans+=city[i]+city[i+1];
                city[i]=0;
                city[i+1]=0;
            }else{
                ans+=x;
                city[i+1]-=x-city[i];
                city[i]=0;
            }
        }else{
            ans+=x;
            city[i]-=x;
        }
    }
    cout<<ans<<endl;
}