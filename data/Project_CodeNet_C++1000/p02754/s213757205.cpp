#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

ll mod = 1e9+7;

ll solve() {
    ll n, a, b; cin >> n >> a >> b;
    if ( a == 0 && b == 0) return 0;
    ll c = a + b;

    return a * (n / c) + min(n % c, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
