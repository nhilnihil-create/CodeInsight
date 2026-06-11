#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (auto &&e : l)
        cin >> e;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (l[i] == l[j] || l[j] == l[k] || l[k] == l[i])
                    continue;
                if (abs(l[i] - l[j]) < l[k] && l[k] < l[i] + l[j])
                    ++ans;
            }
        }
    }
    cout << ans << '\n';
}