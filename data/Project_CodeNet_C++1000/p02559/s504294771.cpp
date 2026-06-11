#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using namespace atcoder;

typedef long long ll;

int main() {
    int N, Q, a, b, c;
    cin >> N >> Q;
    fenwick_tree<ll> fw(N);
    rep(i, N) {
        cin >> a;
        fw.add(i, a);
    }
    while(Q--) {
        cin >> a >> b >> c;
        if (a) {
            cout << fw.sum(b, c) << "\n";
        } else {
            fw.add(b, c);
        }
    }
}