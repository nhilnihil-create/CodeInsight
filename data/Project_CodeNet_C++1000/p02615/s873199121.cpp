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

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    sort(A.rbegin(), A.rend());

    ll ans = 0;
    rep(i,N){
        if (i == 0) continue;
        ans += A[i/2];
    }

    cout << ans << endl;
}