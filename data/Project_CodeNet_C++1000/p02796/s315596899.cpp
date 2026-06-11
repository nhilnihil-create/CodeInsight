#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<long long int, long long int>> robots;

int main() {
    cin >> N;
    robots.resize(N);
    for (int i = 0; i < N; i++) {
        long long int x, l;
        cin >> x >> l;
        robots.at(i) = make_pair(x, l);
    }

    sort(robots.begin(), robots.end(), [](auto const &lhs, auto const &rhs) {
        return lhs.first + lhs.second < rhs.first + rhs.second; 
    });

// 1番右のロボットの右腕はどこまで伸びるか
    long long int right_arm = -1000000001;
    int res = 0;
    for (auto &e: robots) {
        if (e.first - e.second >= right_arm) {
            res++;
            right_arm = e.first + e.second;
        }
    }

    cout << res << endl;
}