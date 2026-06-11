#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    int sum = 0;
    for (auto e : a) sum += e;

    int count = 0;
    for (auto e : a) {
        if (e * 4 * m < sum) continue;
        ++count;
    }

    cout << (m <= count ? "Yes" : "No") << endl;
}

