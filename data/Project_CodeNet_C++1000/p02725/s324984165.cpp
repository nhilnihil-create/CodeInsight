#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    // 複雑に考えすぎた
    // int k, n; cin >> k >> n;
    // V<int> a(n * 2);
    // for(int i = 0; i < n; i++) cin >> a[i];
    // for(int i = 0; i < n; i++){
    //     a[i + n] = a[i] + k;
    // }
    // int ans = IINF;
    // for(int i = 0; i < n; i++){
    //     ans = min(ans, abs(a[i + n - 1] - a[i]));
    // }
    // cout << ans << endl;

    int k, n; cin >> k >> n;
    V<int> a(n + 1);
    for(int i = 0; i < n; i++) cin >> a[i];
    a[n] = k + a[0];

    int maxi = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, a[i + 1] - a[i]);
    }
    cout << k - maxi << endl;

    return 0;
}
