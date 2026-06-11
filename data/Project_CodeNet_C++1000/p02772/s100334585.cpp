#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

ll mod = 1e9+7;

string solve() {
    int n, a; cin >> n;
    rep(i, n) {
        cin >> a;
        if (a % 2 == 0 && (a % 3 != 0 && a % 5 != 0)) {
            return "DENIED";
        }
    }

    return "APPROVED";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
