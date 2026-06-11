#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vp.push_back(make_pair(b, a));
    }

    sort(vp.begin(), vp.end());
    int t = 0;
    for (int i = 0; i < n; i++) {
        t += vp[i].second;
        if (t > vp[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
