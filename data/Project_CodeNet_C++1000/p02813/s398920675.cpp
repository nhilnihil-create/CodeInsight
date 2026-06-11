#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (size_t i = 0; i < n; i++) cin >> p[i];
    for (size_t i = 0; i < n; i++) cin >> q[i];

    vector<int> perm(n);
    for (size_t i = 0; i < n; i++) perm[i] = i+1;
    int order_p = -1;
    int index = 0;
    do {
        bool same = true;
        for (size_t i = 0; i < n; i++) {
            if (perm[i] == p[i]) {
                continue;
            } else {
                same = false;
                break;
            }
        }
        if (same) {
            order_p = index;
            break;
        }
        index++;
    } while(next_permutation(perm.begin(), perm.end()));

    for (size_t i = 0; i < n; i++) perm[i] = i+1;
    int order_q = -1;
    index = 0;
    do {
        bool same = true;
        for (size_t i = 0; i < n; i++) {
            if (perm[i] == q[i]) {
                continue;
            }else{
                same = false;
                break;
            }
        }
        if (same) {
            order_q = index;
            break;
        }
        index++;
    } while(next_permutation(perm.begin(), perm.end()));

    cout << abs(order_p - order_q) << endl;
    return 0;
}
