#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sum = a[n - 1] - a[0];
    for (int i = 1; i < n - 1; i++) {
        sum += abs(a[i]);
    }
    cout << sum << endl;
    int idx = lower_bound(a.begin(), a.end(), 0) - a.begin();
    int front = a[0];
    int back = a[n - 1];
    for (int i = 1; i < n - 1; i++) {
        if (i < idx) {
            cout << back << " " << a[i] << endl;
            back -= a[i];
        } else {
            cout << front << " " << a[i] << endl;
            front -= a[i];
        }
    }
    cout << back << " " << front << endl;
    return 0;
}
