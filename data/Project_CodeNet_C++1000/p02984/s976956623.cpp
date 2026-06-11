#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    long long cum = 0;
    for (int i = 0 ;i < n ;i++) {
        cin >> a[i];
        if (i&1)
            cum -= a[i];
        else
            cum += a[i];
    }

    for (int i = 0 ;i < n ;i++) {
        cout << cum << ' ';
        cum = (a[i] - cum / 2) * 2;
    }
}
