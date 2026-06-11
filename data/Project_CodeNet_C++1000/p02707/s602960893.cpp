#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ans(n, 0);
    while (--n) {
        int a; cin >> a;
        ++ans[a - 1];
    }
    for (auto e : ans) cout << e << endl;
}

