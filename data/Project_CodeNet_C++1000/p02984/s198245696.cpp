#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100007];
int ans[100007];

int main() {
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sum /= 2;
    for (int i = 2; i <= n; i += 2) {
        sum -= a[i];
    }
    ans[1] = sum;
    cout << ans[1] * 2 << ' ';
    for (int i = 2; i <= n; i++) {
        ans[i] = a[i - 1] - ans[i - 1];
        cout << ans[i] * 2 << ' ';
    }
    cout << endl;;
    return 0;
}
