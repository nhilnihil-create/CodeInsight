#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

int head(int n) {
    if (0 <= n && n <= 9) {
        return n;
    }

    return head(n / 10);
}

int tail(int n) {
    return n % 10;
}


int c(int N, int i, int j) {
    int ans = 0;

    FORE(k, 1, N) {
        int hd = head(k);
        int tl = tail(k);

        if (hd == i && tl == j) {
            ans += 1;
        }
    }

    return ans;
}

signed main() {
    int N;

    cin >> N;

    int ans = 0;
    FORE(i, 1, 9) {
        FORE(j, 1, 9) {
            ans += c(N, i, j) * c(N, j, i);
        }
    }

    cout << ans << endl;
}
