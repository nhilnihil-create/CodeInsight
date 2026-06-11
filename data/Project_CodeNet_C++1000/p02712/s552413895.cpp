#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

typedef long long ll;
typedef vector<int> vi;

ll mod = 1e9+7;

ll solve() {
    int n; cin >> n;

    ll sum = 0;
    rep(x, n + 1) {
        if (x % 3 != 0 && x % 5 != 0) 
            sum += x;
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
