#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n),f(n);

    rep(i,n){
        cin>>a[i];    
    }
    rep(i,n)cin>>f[i];
    sort(a.begin(),a.end());
    sort(f.begin(),f.end());
    ll l=-1,r=1e12;
    while(l+1<r){
        auto ok=[&](ll now){
            bool res=true;
            ll ch=0;
            rep(i,n){
               ch+=max((ll)0,a[i]-now/f[n-i-1]);
            }
            if(ch>k)res=false;
            return res;
        };
        ll now=(l+r)/2;
        if(ok(now))r=now;
        else l=now;
    }
    cout<<r<<endl;
    return 0;
}