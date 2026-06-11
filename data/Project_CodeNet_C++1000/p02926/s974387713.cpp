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

typedef complex<double> P;

void solve() {
    int N;
    cin >> N;
    vi X(N), Y(N);
    vector<P> ps(N);
    rep(i, N) {
        cin >> X[i] >> Y[i];
        ps[i] = P(X[i], Y[i]);
    }

    sort(all(ps), [&](P p, P q) {
        return atan2(imag(p), real(p)) < atan2(imag(q), real(q));
    });
    
    double ans = 0;
    rep(i, N) {
        double x = 0, y = 0;
        rep(j, N) {
            x += real(ps[(i + j) % N]);
            y += imag(ps[(i + j) % N]);
            smax(ans, sqrt(x*x + y * y));
        }
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}