#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
int arr[maxn];
signed main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }
    int mx = arr[1], ans = 0;
    for (int i = 2; i <= N; ++i) {
        if (arr[i] > mx) {
            mx = arr[i];
        } else {
            ans += mx - arr[i];
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}