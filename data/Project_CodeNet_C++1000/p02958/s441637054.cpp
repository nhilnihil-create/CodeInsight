#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int diffs {0};
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        if (i != a) {
            diffs++;
        }
    }
    if (diffs == 0 || diffs == 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}