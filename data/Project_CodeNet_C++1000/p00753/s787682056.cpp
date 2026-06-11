#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;

vector<int> prime;
void setPrime(int n) {
    vector<bool> alive(n, true);
    alive[0] = alive[1] = false;
    rep2(i, 2, n + 1) {
        if (alive[i]) {
            prime.emplace_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                alive[j] = false;
            }
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    setPrime(300000);
    int n;
    while (cin >> n, n) {
        cout << upper_bound(all(prime), 2 * n) - upper_bound(all(prime), n) << endl;
    }
}