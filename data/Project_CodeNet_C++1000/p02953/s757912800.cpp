#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0 ;i < n ;i++)
        cin >> a[i];

    int prev = a[0] - 1;
    for (int i = 1 ;i < n ;i++) {
        if (a[i] < prev) {
            cout << "No";
            return 0;
        }

        if (a[i] - 1 >= prev)
            prev = a[i] - 1;
        else
            prev = a[i];
    }

    cout << "Yes";
}
