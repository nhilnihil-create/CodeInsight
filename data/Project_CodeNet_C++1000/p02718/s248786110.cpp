#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);
    reverse(a, a+n);

    double sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];

    if (a[m-1] < sum/(4*m)) cout << "No" << endl;
    else cout << "Yes" << endl;
}