#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    constexpr int mod = 1e9 + 7;
    vector<int> cnt(3, -1);
    long long ans = 1;
    
    int N;
    cin >> N;
    rep(i, N) {
        int a;
        cin >> a;
        int c = 0;
        rep(j, 3) {
            if (cnt[j] == a - 1) ++c;
        }
        ans *= c;
        ans %= mod;
        rep(j, 3) {
            if (cnt[j] == a - 1) {
                ++cnt[j];
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
