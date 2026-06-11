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
    int n, k;
    cin >> n >> k;
    if (k > (n - 1) * (n - 2) / 2) {
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int>> res(n + 1, vector<int>(0));
    int l = 0;
    for (int i = 2; i <= n; i++) {
        res[1].push_back(i);
        l++;
    }
    k -= (n - 1) * (n - 2) / 2;
    for (int i = 2; i <= n; i++) {
        for (int j = i + 1; j <= n && k < 0; j++) {
            res[i].push_back(j);
            k++;
            l++;
        }
    }
    cout << l << endl;
    for (int i = 1; i <= n; i++) {
        for (auto next : res[i]) {
            cout << i << " " << next << endl;
        }
    }
}


