#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)

int main() {
    int k;
    cin >> k;

    int cnt = 0;
    for (int a = 1; a <= k; a++) {
        for (int b = 1; b <= k; b++) {
            for (int c = 1; c <= k; c++) {
                int tmp;
                cnt += __gcd(__gcd(a, b), c);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
