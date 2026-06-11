#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << endl
#else
#define debug(x)
#endif
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N;
long double x[100], y[100];
pair<long double, pair<long double, long double>> a[200];

signed main(){
	cin >> N;
	rep(i, N){
		cin >> x[i] >> y[i];
		a[i] = mp(atan2(y[i], x[i]), mp(x[i], y[i]));
	}
	sort(a, a+N);
	rep(i, N) a[N+i] = a[i];

	long double ans = 0;
	rep(i, N){
		rep(j, N){
			long double X = 0, Y = 0;
			rep(k, j+1){
				X += a[i+k].second.first;
				Y += a[i+k].second.second;
			}
			ans = max(ans, X*X+Y*Y);
		}
	}
	cout << fixed << setprecision(16) << sqrt(ans) << endl;
}