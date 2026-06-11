#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k, sum, ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    vi a(n);
    for (auto& i : a) {
        cin >> i;
        sum += i;
    }

    for (int i = 1; i * i <= sum; ++i) {
        if (!(sum % i)) {
            // First check for i as GCD then sum / i
            ll moves = 0, cur = 0;
            vi delta;
            rep(j, 0, n) {
                if (!(a[j] % i)) continue;

                int change = i - a[j] % i;
                delta.push_back(change);
                cur += change;
            }
            sort(all(delta), greater<int>());
            
            for (auto j : delta) {
                if (!cur) break;
                moves += i - j;
                cur -= i;
            }

            if (moves <= k) ans = max(ans, i);

            moves = 0, cur = 0;
            int other = sum / i;
            delta.clear();

            rep(j, 0, n) {
                if (!(a[j] % other)) continue;

                int change = other - a[j] % other;
                delta.push_back(change);
                cur += change;
            }
            sort(all(delta), greater<int>());

            for (auto j : delta) {
                if (!cur) break;
                moves += other - j;
                cur -= other;
            }

            if (moves <= k) ans = max(ans, other);
        }
    }

    cout << ans;
}
