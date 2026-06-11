#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n, 0), h(n);
    rep(i, n) cin >> h[i];
    v[n - 2] = 1;
    v[n - 1] = 1;
    do {
        int i = 0;
        int tmp = 1;
        for(auto x : v) {
            // cout << x << " ";
            if(x == 1) {
                tmp *= h[i];
            }
            i++;
        }
        
        ans += tmp;
        // cout << "\n";                              // v の要素を表示
    } while(next_permutation(v.begin(), v.end())); // 次の順列を生成
    cout << ans << endl;
    return 0;
}