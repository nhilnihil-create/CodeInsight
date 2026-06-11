#ifdef LOCAL
//#define _GLIBCXX_DEBUG
#endif
//#pragma GCC target("avx512f,avx512dq,avx512cd,avx512bw,avx512vl")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<char> Vc;
typedef vector<P> VP;
typedef vector<vector<ll>> VV;
typedef vector<vector<int>> VVi;
typedef vector<vector<char>> VVc;
typedef vector<vector<vector<ll>>> VVV;
typedef vector<vector<vector<vector<ll>>>> VVVV;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e18+18;
const ll MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define rEach(i, mp) for (auto i = mp.rbegin(); i != mp.rend(); ++i)
#ifdef LOCAL
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define dbgmint(n,arr) rep(i,n){cerr<<arr[i].x<<" ";}cerr<<endl;
#define dbgarrmint(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j].x<<" ";}cerr<<endl;}
#else
#define dbg(...)
#define dbgmap(...)
#define dbgarr(...)
#define dbgdp(...)
#define dbgmint(...)
#define dbgarrmint(...)
#endif
#define out(a) cout<<a<<endl
#define out2(a,b) cout<<a<<" "<<b<<endl
#define vout(v) rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl
#define Uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define fi first
#define se second

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,v.size())i>>v[j];return i;}

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len=vv.size();
    for(int i=0; i<len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}

//ランレングス
vector<pair<char, ll>> run_length_encoding(const string &s) {
    vector<pair<char, ll>> ans;
    ll num = 1;
    rep(i, s.length()-1) {
        if (s[i] == s[i + 1]) {
            num++;
        }
        else {
            ans.emplace_back(mp(s[i], num));
            num = 1;
        }
    }
    ans.emplace_back(mp(s.back(), num));
    return ans;
}

int solve(){
    string s;
    ll k;
    cin>>s>>k;
    vector<pair<char, ll>> rl =  run_length_encoding(s);
    ll ans = 0;
    if(rl.size()==1){
        ll x = rl[0].se;
        x *= k;
        ans = x/2;
    }else{
        ll sz = rl.size();
        if(rl[0].fi == rl[sz-1].fi){
            ll tmp = 0;
            REP(i,1,sz-1){
                tmp += rl[i].se/2;
            }
            tmp *= k;

            ll st = rl[0].se;
            ll la = rl[sz-1].se;
            tmp += (st+la)/2 * (k-1);
            tmp += st/2;
            tmp += la/2;
            ans = tmp;
        }else{
            ll tmp = 0;
            Each(p, rl){
                tmp += p.se/2;
            }
            ans = tmp * k;
        }
    }
    dbg(rl);
    cout<<ans<<endl;
    return  0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);
    solve();
}
