#include "bits/stdc++.h"
using namespace std;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)
typedef long long ll;

int main() {
    ll L, R;
    cin >> L >> R;
    int bor = (R / 2019) * 2019;
    if (L <= bor) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 2019 * 2019;
    L %= 2019;
    R %= 2019;
    for (int i = L; i < R; i++) {
        for (int j = i + 1; j <= R; j++) {
            ans = min(ans, (ll)i * j % 2019);
        }
    }
    cout << ans << endl;
    return 0;
}