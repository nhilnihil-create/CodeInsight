// SmartCoder
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>  // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
using namespace std;

#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define minei(x) min_element(x.begin(), x.end()) - (x).begin()
#define maxei(x) max_element(x.begin(), x.end()) - (x).begin()
#define LSOne(S) (S & (-S))

#define uns(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define acusum(x) accumulate(x.begin(), x.end(), 0)
#define acumul(x) accumulate(x.begin(), x.end(), 1, multiplies<int>());
#define bits(x) __builtin_popcount(x)
#define oo INT_MAX
#define inf 1000000000
#define MAXN 1000007
#define MOD 1000000007

const double pi = acos(-1.0);
const double eps = 1e-11;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, c;
    string s;
    cin >> n >> k >> c;
    cin >> s;
    n++;
    s = "x" + s;
    vector<int> dpL(n + 3, 0), dpR(n + 3, 0);
    vector<int> lastOLeft(n + 3, -10000000), lastORight(n + 3, 10000000);
    for (int i = 1; i <= n; i++) {
        lastOLeft[i] = (s[i] == 'o' ? i : lastOLeft[i - 1]);
        if (s[i] == 'x') dpL[i] = dpL[i - 1];
        if (s[i] == 'o') dpL[i] = 1 + (i - c - 1 >= 0 ? dpL[i - c - 1] : 0);
    }
    for (int i = n; i >= 1; i--) {
        lastORight[i] = (s[i] == 'o' ? i : lastORight[i + 1]);
        if (s[i] == 'x') dpR[i] = dpR[i + 1];
        if (s[i] == 'o') dpR[i] = 1 + (i + c + 1 <= n ? dpR[i + c + 1] : 0);
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'x') continue;
        int lastRight = lastORight[i + 1];
        int lastLeft = lastOLeft[i - 1];

        int right = dpR[i + 1] + (lastRight - c - 1 >= i ? dpL[i - 1] : ((lastRight - c - 1 < n) && (lastRight - c - 1 >= 0) ? dpL[lastRight - c - 1] : 0));
        int left = dpL[i - 1] + (lastLeft + c + 1 <= i ? dpR[i + 1] : ((lastLeft + c + 1 < n) && (lastLeft + c + 1 >= 0) ? dpR[lastLeft + c + 1] : 0));
        int takeIt = 1 + (i - c - 1 >= 1 ? dpL[i - c - 1] : 0) + (i + 1 + c <= n ? dpR[i + 1 + c] : 0);
        if (max(left, right) < k && takeIt == k) {
            cout << i << endl;
        }
    }

    return 0;
}