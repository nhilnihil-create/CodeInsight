#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int ans = 0;
    for(int i = 0; i < n - 2; i++) {
        for(int j  = i + 1; j < n - 1; j++) {
            int idx = lower_bound(v.begin(), v.end(), v[i] + v[j]) - v.begin();
            ans += max(0, idx - (j + 1));
        }
    }

    cout << ans << endl;
    return 0;
}

