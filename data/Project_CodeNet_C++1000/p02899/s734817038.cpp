#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        a.at(tmp-1) = i;
    }

    for (int i = 0; i < n; i++) {
        cout << a.at(i) << (i == n-1 ? "" : " ");
    }

    cout << endl;

    return 0;
}
