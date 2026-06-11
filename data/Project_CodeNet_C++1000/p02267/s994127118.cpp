#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, tmp, count = 0;
    set<int> S;
    cin >> n;
    while (n--) {
        cin >> tmp;
        S.insert(tmp);
    }
    cin >> q;
    while (q--) {
        cin >> tmp;
        count += S.count(tmp);
    }
    cout << count << endl;
    return 0;
}