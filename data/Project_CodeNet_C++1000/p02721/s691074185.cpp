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
    int N, K, C;
    string S, T;
    cin >> N >> K >> C >> S;
    T = S;
    reverse(T.begin(), T.end());
    vector<int> left(N+1), right(N+1);
    int pre = -C - 1;
    int cur = 0;
    REP(i,N){
        if(i - pre > C && S[i] == 'o') cur++, pre = i;
        left[i+1] = cur;
    }
    cur = 0, pre = -C - 1;
    REP(i,N){
        if(i - pre > C && T[i] == 'o') cur++, pre = i;
        right[i+1] = cur;
    }
    REP(i,N){
        if(S[i] == 'x') continue;
        if(left[i] + right[N-i-1] < K) cout << i + 1 << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int T; cin >> T; REP(t,T) solve();
}