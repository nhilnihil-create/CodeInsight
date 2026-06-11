// う　し　た　ぷ　に　き　あ　く　ん　笑
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    bool ans = true;

    for (int i = 1; i < n; i++) {
        if (h[i] > h[i - 1]) {
            h[i]--;
        } else if (h[i] == h[i - 1])
            ;
        else if (h[i] < h[i - 1]) {
            ans = false;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;
}
