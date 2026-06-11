#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
ll gcd(ll x,ll y){
    if (y == 0) return x;
    return gcd(y, x%y);
}
ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}
int main(void){
    ll a,b,c,d;cin>>a>>b>>c>>d;a--;
    ll g=lcm(c,d);
    ll buf1=a/c,buf2=a/d,buf3=b/c,buf4=b/d,buf5=a/g,buf6=b/g;
    ll res=buf3+buf4-buf2-buf1+buf5-buf6;
    res=b-a-res;
    cout<<res<<endl;
}