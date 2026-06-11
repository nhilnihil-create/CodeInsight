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

void solve() {
    int N;
    cin >> N;
    vi A(1 << N);
    rep(i, 1 << N)cin >> A[i];
    sort(A.rbegin(), A.rend());
    deque<int> dq;
    vector<bool> flag(1 << N);
    flag[0] = true;
    rep(i, N) {
        rep(j, 1 << N) if (flag[j])dq.push_back(A[j]);
        rep(j, 1 << N) {
            if (!flag[j] && dq.front()>A[j]) {
                flag[j] = true;
                dq.pop_front();
            }
        }
    }
    bool ans = count(all(flag), true) == 1 << N;
    cout << (ans ? "Yes" : "No") << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}