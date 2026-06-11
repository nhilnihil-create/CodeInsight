#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> d(n);
    for (size_t i = 0; i < n; i++) cin >> d[i];

    sort(d.begin(), d.end());
    int ans = d[n/2] - d[n/2-1];

    cout << ans << endl;
    return 0;
}
