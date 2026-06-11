#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <stack>
#include <queue>
#include <deque>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
#define int ll

typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

// template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//  order_of_key (k) : Number of items strictly smaller than k .
//  find_by_order(k) : K-th element in a set (counting from zero).
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define F first
#define S second
#define show(a) cerr << #a <<" -> "<< a <<"\n"

const int N = 2e5 + 5;
const int oo = 1e16 + 5ll;

int n, ans;

int f(int x) {
    // (n * (n + 1)) / 2 = x
    // n * (n + 1) = x * 2
    int res = sqrtl(x * 2) - 1;
    int nice = res - 2;
    for (int i = res; i <= res + 3; ++i) {
        if ((i * (i + 1)) / 2 <= x) { nice = i; }
    }
    return nice;
}

void solve() {
    cin >> n;
    int nn = n;
    for (int i = 2; i * i <= nn; ++i) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            ++cnt;
        }
        ans += f(cnt);
    }
    if (n > 1) {
        ans += 1;
    }
    cout << ans;
}

 main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	while (tt --) {
		solve();
	}
	return 0;
}
