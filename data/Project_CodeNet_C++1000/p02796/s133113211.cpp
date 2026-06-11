#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> robot(n, pair<int, int> {});

    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        robot[i] = { x + l, x - l };
    }

    sort(robot.begin(), robot.end());

    int count = 0;
    int last = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (robot[i].second >= last) {
            count++;
            last = robot[i].first;
        }
    }

    cout << count << endl;

    return 0;
}