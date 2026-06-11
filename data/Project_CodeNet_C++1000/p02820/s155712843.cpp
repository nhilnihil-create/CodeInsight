#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX/10
#define rep(i,n) for(int i=0;i<n;i++)
#define krep(i,k,n,m) for(int i=k;i<n;i+=m)
#define erep(i,k,n) for(int i=k;i<n;i++)
#define mod 1000000007
//最大公約数
int gcd(int s,int t){
    if(t==0)return s;
    return gcd(t,s%t);
}
signed main(){
    int n,m;
    cin>>n>>m;
    int s,p,r;
    cin>>s>>p>>r;
    string t;
    int ans=0;
    cin>>t;
    rep(i,n-m){
        if(t[i]==t[i+m]){
            t[i+m]='1';
        }
        
    }
    rep(i,n){
        if(t[i]=='r'){
            ans+=r;
        }
        else if(t[i]=='s'){
            ans+=s;
        }
        else if(t[i]=='p'){
            ans+=p;
        }
    }
    cout<<ans<<endl;
}
