#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;

int R, S, P;
int point(char c) {
    if (c == 'r') return P;
    else if (c == 's') return R;
    return S;
}

int index(char c) {
    if (c == 'r') return 0;
    else if (c == 's') return 1;
    return 2;
}
int main()
{
    int N, K;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    vector<int> able(N);

    ll ans = 0;
    rep(i, N) {
        if (i - K >= 0) {
            if (T[i] != T[i - K]) {
                ans += point(T[i]);
                able[i] = 1;
            }
            else if (able[i - K] == 0) {
                ans += point(T[i]);
                able[i] = 1;
            }
        }
        else {
            ans += point(T[i]);
            able[i] = 1;
        }
    }

    cout << ans << endl;
    return 0;
}