#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double v[50];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v, v + n);
    double ans = v[0];
    for (int i = 1; i < n; i++) ans = (ans + v[i]) / 2;
    
    cout << ans << endl;
}
