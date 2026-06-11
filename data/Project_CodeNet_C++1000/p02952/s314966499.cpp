#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int ans = 0, N;
    string n;
    cin >> n;
    N = atoi(n.c_str());
    for (int i = 0; i <= n.size(); i += 2) {
        for (int j = pow(10, i); j < pow(10, i + 1); ++j) {
            if (j <= N)
                ans++;
            else {
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
}