#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, q; cin >> n >> k >> q;
    vector<int> p(n);
    for (int i = 0; i < q; ++i) {
        int a; cin >> a;
        ++p[a - 1];
    }
    for (auto e : p) {
        if (0 < k - q + e) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

