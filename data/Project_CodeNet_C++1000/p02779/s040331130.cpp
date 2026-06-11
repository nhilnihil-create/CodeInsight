#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);

    sort(a.begin(), a.end());

    string res = "YES";
    for (int i = 1; i < n; i++) {
        if (a.at(i-1) == a.at(i)) res = "NO";
    }

    cout << res << endl;

    return 0;
}
