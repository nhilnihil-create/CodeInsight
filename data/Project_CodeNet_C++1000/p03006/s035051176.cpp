#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;


int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> point(N);
    set<pair<int, int>> points;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        point[i] = {x, y};
        points.insert(point[i]);
    }

    sort(point.begin(), point.end(), [](auto &left, auto &right) {
            if(left.first == right.first)
                return left.second > right.second;
             return left.first > right.first;
    });

    map<pair<int, int>, int> m;
    for(int i=0; i< point.size() - 1; ++i) {
        int xa = point[i].first;
        int ya = point[i].second;
        for(int j=i+1; j < point.size(); ++j) {
            int xb = point[j].first;
            int yb = point[j].second;
            pair<int, int> pp = {xa-xb, ya-yb};
            m[pp]++;
        }
    }

    auto max_m = 0;
    auto max_p = 0;
    auto max_q = 0;
    for(auto itr: m) {
        if(max_m < itr.second) {
            max_m = itr.second;
            max_p = itr.first.first;
            max_q = itr.first.second;
        }
    }
    int ret = 0;
    for(int i=0; i<point.size(); ++i) {
        auto p = point[i];
        if(points.count(p) == 0) {
            continue;
        }
        ret++;
        while(points.count(p)) {
            points.erase(p);
            p.first  -= max_p;
            p.second -= max_q;
        }
    }

//    cout << max_p << " " << max_q << endl;
    cout << ret << endl;

    return 0;
}

