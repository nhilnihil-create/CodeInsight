/*
 * Author:  heyuhhh
 * Created Time:  2019/11/18 18:16:10
 */
#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 300 + 5;

int n, K;

int h[N];
ll dp[N][N];

void run(){
    for(int i = 1; i <= n; i++) cin >> h[i];
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n - K; i++) {
        for(int j = i; j <= n; j++) {
            for(int k = 0; k < j; k++) {
                dp[j][i] = min(dp[j][i], dp[k][i - 1] + max(0, h[j] - h[k]));   
            }
        }   
    }
    ll ans = INF;
    for(int i = 1; i <= n; i++) ans = min(ans, dp[i][n - K]);
    if(ans == INF) ans = 0;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> K) run();
    return 0;
}//others