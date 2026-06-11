#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    string ans = "YES";
    for (size_t i = 1; i < n; i++) {
        if (a[i] == a[i-1]) ans = "NO";
    }

    cout << ans << endl;
    return 0;
}
