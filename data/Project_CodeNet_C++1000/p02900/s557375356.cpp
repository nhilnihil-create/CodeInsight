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

ll GCD(ll a, ll b){
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    if(b == 0) return a;
    else return GCD(b, a%b);
}
void solve(){
    ll a, b; cin >> a >> b;
    vector<ll> cd;
    ll gcd = GCD(a, b);
    if(gcd == 1){
        cout << 1 << endl;
        exit(0);
    }
    for(ll i=1; i*i<=gcd; i++){
        if(gcd%i == 0){
            cd.pb(i);
            cd.pb(gcd/i);
        }
    }
    sort(ALL(cd));
    ll res = 1;
    for(ll i=1; i<cd.size(); i++){
        if(cd[i] != -1){
            res++;
            ll div = cd[i];
            for(ll j=i; j<cd.size(); j++){
                if(cd[j]%div == 0) cd[j] = -1;
            }
        }
    }
    cout << res << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}