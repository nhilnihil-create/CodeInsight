#include <cmath>
#include <iostream>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int p = i; p < n; p++)

bool option(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    bool f = true;
    int n, tmp;
    map<int, int> a;
    map<int, int>::iterator it;

    cin >> n;

    rep(0, n) {
        cin >> tmp;
        a[tmp]++;
    }

    for (it = a.begin(); it != a.end(); it++) {
        if (it->second > 1) {
            f = !f;
            break;
        }
    }

    cout << ((f) ? "YES" : "NO") << endl;

    return 0;
}
