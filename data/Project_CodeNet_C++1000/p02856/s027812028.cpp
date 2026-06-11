#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int m;
ll ans, sum; 

ll count(ll digit, ll times) {
    if (times == 1) return digit;
    else {
        ll tmp = digit * 2, moves = 1;
        if (tmp >= 10) {
            ++moves;
            tmp = tmp % 10 + 1;
        }

        ans += (times / 2) * moves;
        ll res = count(tmp, times / 2);
        if (times % 2) {
            tmp = digit + res, moves = 1;
            if (tmp >= 10) {
                ++moves;
                tmp = tmp % 10 + 1;
            }
            ans += moves;
            res = tmp;
        }
        return res;
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        ll d, c;
        cin >> d >> c;
        if (sum) ++ans;
        sum += count(d, c);
        if (sum >= 10) {
            sum = sum % 10 + 1;
            ++ans;
        }
    }
    cout << ans;
}
