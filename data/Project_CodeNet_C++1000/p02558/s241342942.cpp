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
#include <atcoder/dsu>
typedef long long ll;
using namespace std;
using namespace atcoder;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    dsu d(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin>>t>>u>>v;
        if (t == 0) {
            d.merge(u, v);
        }
        else {
            if (d.same(u, v)) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }

	return 0;
}
