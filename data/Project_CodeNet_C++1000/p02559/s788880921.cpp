#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N, Q;
    cin >> N >> Q;

    fenwick_tree<ll> fw(N);
    rep(i, N) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    rep(i, Q) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 0) {
            fw.add(a, b);
        }

        if (t == 1) {
            cout << fw.sum(a, b) << endl;
        }
    }
}