#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;
//using namespace atcoder;

int main(){
    ll S;
    cin >> S; // a*1e9 - 1*b = S
    ll q = (S+ll(1e9)-1)/ll(1e9);
    ll r = S%ll(1e9);
    r = (ll(1e9) - r) % ll(1e9);
    vector<ll> a(6);
    a[0] = q;
    a[1] = r;
    a[2] = 1;
    a[3] = 1e9;
    a[4] = 0;
    a[5] = 0;
    PR(a,6);
}