#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<double, double> P;
typedef tuple<int, int, int> T;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

string s;
int q;
int t[200100], f[200100];
char c[200100];

string solve() {
    deque<char> dq;
    for (char a : s) {
        dq.push_back(a);
    }

    int r = 0;
    for (int i = 0; i < q; i++) {
        if (t[i] == 1) {
            r = 1 - r;
        } else if ((r == 0 && f[i] == 1) || (r == 1 && f[i] == 2)) {
            dq.push_front(c[i]);
        } else {
            dq.push_back(c[i]);
        }
    }

    string res = "";
    if (r == 0) {
        while (!dq.empty()) {
            res += dq.front(); dq.pop_front();
        }
    } else {
        while (!dq.empty()) {
            res += dq.back(); dq.pop_back();
        }
    }
    return res;
}

void input() {
    cin >> s >> q;
    for (int i = 0; i < q; i++) {
        cin >> t[i];
        if (t[i] == 2) {
            cin >> f[i] >> c[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
