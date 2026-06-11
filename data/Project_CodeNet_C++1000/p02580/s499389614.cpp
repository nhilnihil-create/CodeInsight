#include <iostream>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;
int h, w;
int num_of_bombs;

int main() {
    scanf("%d %d", &h, &w);
    scanf("%d", &num_of_bombs);

    vector<int> x_cnt(h, 0);
    vector<int> y_cnt(w, 0);
    set<pair<int, int>> s;

    for (int i = 0; i < num_of_bombs; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        x_cnt[x]++;
        y_cnt[y]++;
        s.emplace(x, y);
    }

    int max_x = 0, max_y = 0;
    for (int i = 0; i < h; ++i) {
        max_x = max(max_x, x_cnt[i]);
    }
    for (int i = 0; i < w; ++i) {
        max_y = max(max_y, y_cnt[i]);
    }

    vector<int> xs, ys;
    for (int i = 0; i < h; ++i) {
        if (max_x == x_cnt[i]) {
            xs.push_back(i);
        }
    }
    for (int i = 0; i < w; ++i) {
        if (max_y == y_cnt[i]) {
            ys.push_back(i);
        }
    }

    long long max_ans = max_x + max_y;
    for (auto a : xs) {
        for (auto b : ys) {
            if (s.find({a, b}) == s.end()) {
                printf("%lld\n", max_ans);
                return 0;
            }
        }
    }

    max_ans--;
    printf("%lld\n", max_ans);
    return 0;
}
