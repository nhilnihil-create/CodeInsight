#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000000LL;
constexpr int inf = 1000000000;

int main() {
    int n;
    cin >> n;
    vector<int> positive, negative;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a >= 0) {
            positive.push_back(a);
        }
        else {
            negative.push_back(a);
        }
    }

    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());

    if (positive.size() == 0) {
        positive.push_back(negative.back());
        negative.pop_back();
    }
    else if (negative.size() == 0) {
        negative.push_back(positive.back());
        positive.pop_back();
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i < positive.size(); ++i) {
        ans.push_back({negative[0], positive[i]});
        negative[0] -= positive[i];
    }

    for (int i = 0; i < negative.size(); ++i) {
        ans.push_back({positive[0], negative[i]});
        positive[0] -= negative[i];
    }

    cout << positive[0] << endl;
    for (auto x : ans) {
        cout << x.first << " " << x.second<< endl;
    }

    return 0;
}