#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

ll mod = 1e9+7;

ll solve() {
    int x, n, a; cin >> x >> n;
    unordered_set<int> num_set;
    rep(i, n) {
        cin >> a;
        num_set.insert(a);
    }
    int left = x, right = x;
    while (num_set.count(left)) {
        left--;
    }
    while (num_set.count(right)) {
        right++;
    }

    return (x - left <= right - x) ? left : right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
