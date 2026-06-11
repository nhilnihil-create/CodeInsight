#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <set>
#include <atcoder/fenwicktree>
typedef long long ll;
using namespace std;
using namespace atcoder;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> fw(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.add(i, a);
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }
    return 0;
}
