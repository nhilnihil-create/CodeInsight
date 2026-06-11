#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p){os<<"("<<p.first<<","<< p.second<<")";return os;}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v){os<<"{";REP(i,(int)v.size()){if(i)os<<",";os<<v[i];}os<<"}";return os;}
template <typename T, size_t S> void printArray(const T (&array)[S]){for(auto val : array)std::cout << val << ", ";std::cout << "\n";}
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
const double PI=acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;
template<class T>inline bool chmax(T& a, T b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T& a, T b){if(a > b){a = b; return 1;}return 0;}
const ll INF = 1LL<<60;
//const int dy[4] = {0, 1, 0, -1};
//const int dx[4] = {1, 0, -1, 0};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> ac(n+1), rac(n+1);
    vector<ll> allocn(n+1);
    for(ll i=0; i<=n; i++) allocn[i] = i%MOD;
    ac[0] = allocn[0]%MOD, rac[n] = allocn[n]%MOD;
    for(ll i=0; i<n; i++){
        ac[i+1] = (ac[i]%MOD + allocn[i+1]%MOD)%MOD;
    }
    for(ll i=n; i>0; i--){
        rac[i-1] = (rac[i]%MOD + allocn[i-1]%MOD)%MOD;
    }
    //cout << ac << endl;
    //cout << rac << endl;
    
    ll res = 0;
    for(ll i=k-1; i<=n; i++){
        ll diff = (rac[n-i] - ac[i])%MOD;
        if(diff < 0) diff += MOD;
        res = res%MOD + (diff + 1)%MOD;
    }
    cout << res << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}