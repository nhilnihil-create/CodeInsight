#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k; cin >> n >> k;

    vector<bool> has(n, false);
    while (k--) {
        int d; cin >> d;
        while (d--) {
            int a; cin >> a;
            has[a - 1] = true;
        }
    }

    int ans = 0;
    for (auto e : has) ans += !e;

    cout << ans << endl;
}

