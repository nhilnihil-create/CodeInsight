#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "Yes" : "No")

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int siz = 1e6 + 10;
const int SIZ = 1e6 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "3";

int a[siz];
int lpf[SIZ];
vector <int> prime;

void sieve() {
    for (int i = 2; i < SIZ; i++) {
        if (!lpf[i]) {
            lpf[i] = i;
            prime.push_back(i);
        }

        for (int j = 0; j < sz(prime) && prime[j] <= lpf[i] && i * prime[j] < SIZ; j++) {
            lpf[i * prime[j]] = prime[j];
        }
    }
}

vector <int> factorize(int x) {
    vector <int> res;
    while (x != 1) {
        if (res.empty() || lpf[x] != res.back()) {
            res.push_back(lpf[x]);
        }
        x /= lpf[x];
    }

    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    sieve();

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    set <int> divs;
    int g = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        g = __gcd(g, a[i]);
        for (auto &x : factorize(a[i])) {
            if (divs.find(x) == divs.end()) {
                divs.insert(x);
            }
            else {
                ans = 1;
            }
        }
    }

    if (ans == 1) {
        if (g != 1) {
            ans = 2;
        }
    }

    switch(ans) {
        case 0:
            return cout << "pairwise coprime" << "\n", 0;
        case 1:
            return cout << "setwise coprime" << "\n", 0;
        default:
            return cout << "not coprime" << "\n", 0;
    }

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
