#include <iostream>

using namespace std;

int n;
int a[25];
int q;

bool solve(int sum, int i) {
    if (sum == 0) {
        return true;
    }
    if (i == n) {
        return false;
    }
    return solve(sum, i + 1) || solve(sum - a[i], i + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        cout << (solve(tmp, 0) ? "yes" : "no") << endl;
    }
}