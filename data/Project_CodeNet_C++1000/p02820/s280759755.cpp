#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, K, R, S, P;
string T;
bool is_win[100100];
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K >> R >> S >> P >> T;
    int ans = 0;
    rep(i, N) {
        if (T[i]=='r') {
            if (i<K) {
                ans += P;
                is_win[i] = true;
            }
            else {
                if (T[i-K]!='r' || !is_win[i-K]) {
                    ans += P;
                    is_win[i] = true;
                }
            }
        }
        else if (T[i]=='s') {
            if (i<K) {
                ans += R;
                is_win[i] = true;
            }
            else {
                if (T[i-K]!='s' || !is_win[i-K]) {
                    ans += R;
                    is_win[i] = true;
                }
            }
        }
        else {
            if (i<K) {
                ans += S;
                is_win[i] = true;
            }
            else {
                if (T[i-K]!='p' || !is_win[i-K]) {
                    ans += S;
                    is_win[i] = true;
                }
            }
        }
    }
    cout << ans << endl;
}
