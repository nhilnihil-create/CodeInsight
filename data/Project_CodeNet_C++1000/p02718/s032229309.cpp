#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

ll mod = 1e9+7;

string solve() {
    int n, m, a; cin >> n >> m;
    vi nums;
    rep(i, n) {
        cin >> a;
        nums.push_back(a);
    }
    sort(nums.rbegin(), nums.rend());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    rep(i, m) {
        if (nums[i] / static_cast<double>(sum) < 1 / static_cast<double>(4 * m)) {
            return "No";
        }
    }

    return "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
