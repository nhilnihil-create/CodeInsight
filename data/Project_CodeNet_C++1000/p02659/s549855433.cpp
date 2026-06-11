#include <bits/stdc++.h>

using namespace std;

using llong = long long int;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int MOD = 1000000007;
const static int INF = 1<<30;
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};

template<typename S, typename T, typename U> 
map<S, T> factorization(U p) {
    map<S, T> M;
    U i = 2;
    while (i * i <= p) {
        if (p % i == 0) {
            ++M[i];
            p /= i;
        } else {
            ++i;
        }
    }

    if (p != 1) ++M[p];

    return M;
}

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    llong a;
    string b;
    cin >> a >> b;

    llong b100 = (b[0] - '0')*100 + (b[2] - '0')*10 + (b[3] - '0');

    cout << a*b100/100LL << endl;

    return 0;
}