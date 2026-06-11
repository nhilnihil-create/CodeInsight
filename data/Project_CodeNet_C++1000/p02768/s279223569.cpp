#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define pb            push_back
#define x             first
#define y             second
#define sz(v)         (int)v.size()
#define all(x)        (x).begin(),(x).end()
#define PI            3.14159265358979
#define N             200005

const int mod=1e9+7;
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}
int solve(){
    int n,a,b; cin>>n>>a>>b;
    int ans=pw(2,n,mod);
    ans=(ans-1+mod)%mod;
    int t1=1,t2=1;
    for(int i=1; i<=a; i++){
        t1=(((t1*(n-i+1))%mod)*pw(i,mod-2,mod))%mod;
    }
    for(int i=1; i<=b; i++){
        t2=(((t2*(n-i+1))%mod)*pw(i,mod-2,mod))%mod;
    }
    ans=(ans-t1+mod)%mod;
    ans=(ans-t2+mod)%mod;
    cout<<ans;
    return 0;
}

signed main() {
    ios::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}