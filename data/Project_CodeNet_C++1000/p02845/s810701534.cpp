#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
const long long MOD = 1000000007;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 1;
    vector<int> RGB(3, 0);
    rep(i, N) {
        int cnt = 0;
        rep(j, 3) {
            if (RGB[j] == A[i]) cnt++;
        }
        rep(j, 3) {
            if (RGB[j] == A[i]) {
                RGB[j]++;
                break;
            }
        }
        ans *= (ll)cnt;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
