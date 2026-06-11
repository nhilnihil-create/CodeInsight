#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void f(int x, int y) {
    cout << x << ' ' << y << endl;
}

void solve() {
    int N;
    cin >> N;
    int digits = 0;
    for (; (1 << digits) <= N; digits++);
    if (N == (1 << (digits - 1))) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    f(1, 2);
    f(1, 3);
    f(2, 3 + N);
    f(3, 2 + N);
    f(2 + N, 1 + N);
    for (int i = 4; i < N; i += 2) {
        int j = i + 1;
        f(1, i);
        f(1, j);
        f(i, j + N);
        f(j, i + N);
    }

    if (N % 2 == 0) {
        int x = 1 << (digits - 1);
        int y = N ^ x ^ 1;
        f(x, N);
        f(y, N + N);
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}