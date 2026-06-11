#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <vector>
#include <deque>

using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    vector<pair<int, int>> digit(m);
    for (int i = 0; i < m; ++i) {
        cin >> digit[i].first >> digit[i].second;
    }

    for (int x = 0; x < 1000; ++x) {
        int nx = x;
        int num_of_digits = 1;

        vector<int> num;
        num.push_back(nx % 10);
        nx /= 10;

        while (nx > 0) {
            num_of_digits++;
            num.push_back(nx % 10);
            nx /= 10;
        }
        if (num_of_digits != n) continue;

        reverse(num.begin(), num.end());
        bool valid = true;
        for (int i = 0; i < m; ++i) {
            if (num[digit[i].first - 1] != digit[i].second) {
                valid = false;
            }
        }
        if (valid) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}