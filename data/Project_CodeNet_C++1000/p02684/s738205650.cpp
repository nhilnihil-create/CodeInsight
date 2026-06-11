#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

const int D = 60;

int main(){
    ll N, K; cin >> N >> K;
    vector<vector<int>> to(60, vector<int>(N,0));
    rep(i,N) cin >> to[0][i];
    rep(i,N) to[0][i]--;

    rep(i,59){
        rep(j,N){
            to[i+1][j] = to[i][to[i][j]];
        }
    }

    int current = 0;
    for(int i = D-1; i>=0; i--){
        ll l = 1LL << i;
        if (l <= K){
            current = to[i][current];
            K -= l;
        }
    }

    cout << current + 1 << endl;
}

    