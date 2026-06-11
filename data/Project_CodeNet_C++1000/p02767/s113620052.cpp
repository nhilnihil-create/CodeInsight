#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

ll mod = 1e9+7;

ll solve() {
    int N, a; cin >> N;
    vi nums;
    rep(i, N) {
        cin >> a;
        nums.push_back(a);
    }

    int res = numeric_limits<int>::max();
    reps(p, 1, 101) {
        int sum = 0;
        for (auto num : nums) {
            sum += (num - p)*(num - p);
        }
        res = min(res, sum);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
