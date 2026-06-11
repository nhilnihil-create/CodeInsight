#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
using namespace std;
using ll=long long;
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }

int main(){
    ll x,k,d;
    cin>>x>>k>>d;

    if(x<0) x=-x;
    ll n=min(k,x/d);
    k-=n;
    x-=n*d;
    if(k%2==0) cout<<x<<endl;
    else cout<<abs(d-x)<<endl;

    return 0;
}