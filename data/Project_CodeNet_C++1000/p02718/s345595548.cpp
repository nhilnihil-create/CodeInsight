#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        total += a.at(i);
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    if (a.at(m-1) * 4 * m >= total) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}