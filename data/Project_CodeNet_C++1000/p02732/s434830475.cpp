#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    vector<int> count(n);
    for (auto e : a) ++count[e - 1];

    int64_t all = 0;
    for (auto e : count) all += int64_t(e) * (e - 1) / 2;

    for (auto e : a) {
        --e;
        cout << (all - (count[e] * (count[e] - 1) / 2) + ((count[e] - 1) * (count[e] - 2) / 2)) << endl;
    }
}

