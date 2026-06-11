#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

ll mod = 1e9+7;

ll solve() {
    int n; cin >> n;
    ll sum = 0;
    sum += (n / 500) * 1000;
    n %= 500;
    sum += (n / 5) * 5;
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
