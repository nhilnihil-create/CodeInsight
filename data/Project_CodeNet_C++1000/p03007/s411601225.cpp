#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin>>n;
    vl as(n);
    cin>>as;

    ll M = -LINF, Mi = -1;
    ll m = LINF, mi = -1;
    rep(i, n) {
        if (as[i] > M) {
            M = as[i];
            Mi = i;
        }
        if (as[n - i - 1] < m) {
            m = as[n - i - 1];
            mi = n - i - 1;
        }
    }

    ll ans = 0;
    rep(i, n) {
        if (i == Mi || i == mi) continue;
        if (as[i] > 0) m -= as[i];
        else M -= as[i];
    }
    ans = M - m;
    cout<<ans<<endl;

    rep(i, n) {
        if (i == mi || i == Mi) continue;
        if (as[i] > 0) {
            cout<<as[mi]<<" "<<as[i]<<endl;
            as[mi] -= as[i];
        }
        else {
            cout<<as[Mi]<<" "<<as[i]<<endl;
            as[Mi] -= as[i];
        }
    }
    cout<<as[Mi]<<" "<<as[mi]<<endl;
}