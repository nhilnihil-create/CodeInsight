#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
	int n, q;
    cin >> n >> q;
    fenwick_tree<ll> fw(n);
    for (int i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        fw.add(i, ai);
    }

    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t) {
            cout << fw.sum(a, b) << endl;
        } else {
            fw.add(a, b);
        }
    }
}
