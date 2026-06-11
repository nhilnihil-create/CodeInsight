#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += v[i/2];
    }
    cout << ans << endl;
    return 0;
}
