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

    ll t1, t2, a1, a2, b1, b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;

    ll da = t1 * a1 + t2 * a2;
    ll db = t1 * b1 + t2 * b2;
    if (da == db) {
        cout<<"infinity"<<endl;
        return 0;
    }
    if (db < da) {
        swap(a1, b1);
        swap(a2, b2);
        swap(da, db);
    }
    if (a1 * t1 < b1 * t1) {
        cout<<0<<endl;
        return 0;
    }

    ll res = db - da;
    ll r = (a1 - b1) * t1;
    ll ans = r / res * 2 + 1;
    if (r % res == 0) ans--;
    cout<<ans<<endl;
}
