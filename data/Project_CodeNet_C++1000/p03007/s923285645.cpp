#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 1e5 + 5;
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = a[n - 1] - a[0];

    for (int i = 1; i + 1 < n; i++) {
        ans += abs(a[i]);
    }

    cout << ans << "\n";

    int anime = a[0];

    for (int i = 1; i + 1 < n; i++) {
        if (a[i] > 0) {
            cout << anime << " " << a[i] << "\n";
            anime -= a[i];
        }
    }

    cout << a[n - 1] << " " << anime << "\n";

    anime = a[n - 1] - anime;

    for (int i = 1; i + 1 < n; i++) {
        if (a[i] <= 0) {
            cout << anime << " " << a[i] << "\n";
            anime -= a[i];
        }
    }

    return 0;
}