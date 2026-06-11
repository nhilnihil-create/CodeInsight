#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
 
const ll INF = 1LL << 60;
 
ll N, K;
string S;
int main() {
    cin >> N >> K >> S;
 
    ll score = 0;
    rep(i, N - 1) {
        if (S[i] == S[i + 1]) score++;
    }
 
    ll ans = min(N - 1, score + 2 * K);
    cout << ans << endl;
}