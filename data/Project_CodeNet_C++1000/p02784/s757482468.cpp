#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

ll mod = 1e9+7;

string solve() {
    int H, N, a; cin >> H >> N;
    rep(i, N) {
        cin >> a;
        H -= a;
    }
    if (H <= 0) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
