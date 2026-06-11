#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += lower_bound(v.begin(), v.end(), v[i] + v[j]) - (v.begin() + j) - 1;
        }
    }
    cout << ans << endl;
}
