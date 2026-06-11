#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<vector<ll>> VV;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define rep(i, n) REP(i, 0, n)
const int INF=1e9;
const int MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define ALL(v) v.begin(), v.end()
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#define dbgmap(mp) for (auto i = mp.begin(); i != mp.end(); ++i) { cout << i->first <<":"<<i->second << endl;}
#define sum(v) accumulate(ALL(v),0)
#define fi first
#define se second

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<" ";
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
//    vector<ll> a(n);
    priority_queue<ll> a;
    for(ll i=0; i<n; i++) {
        ll tmp;
    	cin>>tmp;
    	a.push(tmp);
    }

    for (ll i = 0; i < m; i++) {
        ll tmp = a.top();
        a.pop();
        tmp = tmp / 2;
        a.push(tmp);
    }
    ll ans=0;
    for (ll i = 0; i < n; i++) {
        ans += a.top();
        a.pop();
    }
    cout<<ans<<endl;
    return  0;
}
