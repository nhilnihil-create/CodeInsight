#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x[100];
    cin >> n;
    for (int i=0; i<n; i++) {
        scanf("%d", &x[i]);
    }
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += x[i];
    }
    int p = round((double)sum/n);
    int ans = 0;
    for (int i=0; i<n; i++) {
        ans += (x[i]-p)*(x[i]-p);
    }
    cout << ans << endl;

    return 0;
}
