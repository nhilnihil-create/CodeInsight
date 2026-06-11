#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> id(n), id2(n);
    for (int i = 1; i <= n; i++) {
        id.at(i - 1) = i;
        id2.at(i - 1) = i;
    }
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> q.at(i);
    }
    int pi = 1;
    if (p != id) {
        while (next_permutation(id.begin(), id.end())) {
            pi++;
            if (id == p) break;
        }
    }
    id = id2;
    int qi = 1;
    if (q != id) {
        while (next_permutation(id.begin(), id.end())) {
            qi++;
            if (id == q) break;
        }
    }
    cout << abs(pi - qi) << endl;
    return 0;
}