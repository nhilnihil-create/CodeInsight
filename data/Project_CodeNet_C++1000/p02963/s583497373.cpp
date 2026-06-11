#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

ll X[3];
ll Y[3];

int main(){
    ll S;
    cin >> S;
    X[1] = 1;
    Y[1] = 1e9;
    X[2] = (S+ll(1e9)-1)/ll(1e9);
    ll r = S%ll(1e9);
    Y[2] = (ll(1e9) - r)%ll(1e9);
    cout << X[0] <<" "<<Y[0]<<" "<<X[1]<<" "<<Y[1]<<" "<<X[2]<<" "<<Y[2]<< endl;
}