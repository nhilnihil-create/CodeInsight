#include <iostream>
#include <algorithm>

using namespace std;

int make_before_tax(int price, int rate) {
    int before = (price * 100 + 99 + rate) / (100 + rate);
    if (before * (100 + rate) / 100 != price) {
        throw "tsurai";
    }
    return before;
}

int solve(int x, int y, int s) {
    int max_total = 0;
    for (int a = 1; a < s; ++a) {
        try {
            int changed_a = make_before_tax(a, x) * (100 + y) / 100;
            int changed_b = make_before_tax(s - a, x) * (100 + y) / 100;
            max_total = max(max_total, changed_a + changed_b);
        } catch (const char *) {
            continue;
        }
    }
    return max_total;
}

int main() {
    int x, y, s;
    while (true) {
        cin >> x >> y >> s;
        if (x == 0) {
            return 0;
        }
        cout << solve(x, y, s) << endl;
    }
}