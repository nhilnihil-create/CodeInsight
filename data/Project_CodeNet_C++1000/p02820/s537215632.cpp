#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;

int N, K, R, S, P;

int getScore(char c) {
    if (c == 'r') return P;
    if (c == 's') return R;
    return S;
}

int main()
{
    string T;
    cin >> N >> K >> R >> S >> P >> T;

    vector<bool> check(N);

    int ans = 0;
    rep(i, N) {
        if (i >= K) {
            if (T[i] == T[i - K] && check[i - K]) continue;
            ans += getScore(T[i]);
            check[i] = true;
        }
        else if (i < K) {
            ans += getScore(T[i]);
            check[i] = true;
        }
        // cout << ans << endl;
    }

    cout << ans << endl;
    return 0;
}