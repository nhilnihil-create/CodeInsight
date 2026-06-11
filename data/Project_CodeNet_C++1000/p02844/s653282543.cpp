#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

void solve(){
    int N;
    string S;
    cin >> N >> S;
    vector<vector<int>> idx(10);
    REP(i,N) idx[S[i]-'0'].emplace_back(i);
    int ans = 0;
    REP(i,10) REP(j,10) REP(k,10){
        int cur = -1;
        auto itr = lower_bound(idx[i].begin(), idx[i].end(), cur + 1);
        if(itr == idx[i].end()) continue;
        cur = *itr;
        itr = lower_bound(idx[j].begin(), idx[j].end(), cur + 1);
        if(itr == idx[j].end()) continue;
        cur = *itr;
        itr = lower_bound(idx[k].begin(), idx[k].end(), cur + 1);
        if(itr == idx[k].end()) continue;
        ans++;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int T; cin >> T; REP(t,T) solve();
}