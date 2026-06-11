#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

void operation(vector<int> &a) {
    vector<int> b(a.size(), 0);
    for (int i = 0; i < (long long)a.size(); i++) {
        int start = i - a[i];
        int end = i + a[i] + 1;
        if (start < 0) start = 0;
        b[start]++;
        if (end < (long long)a.size()) b[end]--;
    }

    for (int i = 1; i < (long long)a.size(); i++) {
        b[i] += b[i - 1];
    }

    a = b;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++) {
        operation(a);
        if (a == vector<int>(n, n)) break;
    }

    for (auto &&ai : a) {
        cout << ai << " ";
    }
    cout << endl;
}
