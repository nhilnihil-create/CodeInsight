#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        p[i] = make_pair(x + l, x - l);
    }
    sort(p.begin(), p.end());

    int ans = n;
    for (int i = 0; i < n;) {
        auto now = p[i++];
        while (now.first > p[i].second && i < n) { i++, ans--; }
    }
    cout << ans << endl;
}