#include <bits/stdc++.h>
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
 
int main(){
    ll M;
    cin >> M;
    vector<ll> c(M), d(M);
    rep(i,M){
        cin >> d[i] >> c[i];
    }
    ll ans = 0;
    ll sum = 0;
    ll sum_b = 0;
    rep(i,M){
        ll tmp = d[i]*c[i];// + r;
        sum += c[i];
        sum_b += tmp;
        //r = tmp % 10;
    }
    while(sum_b >= 10){
        ll r = sum_b % 10;
        sum_b /= 10;
        ans += sum_b;
        sum_b += r;
    }
    cout << ans+sum-1 << endl;
}