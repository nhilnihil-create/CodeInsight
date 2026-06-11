#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;

	ll X[100], Y[100];
	rep(i, N) cin >> X[i] >> Y[i];

	double kotae = 0;
	rep(i, N) {
		ll x = 0;
		ll y = 0;
		rep(j, N) {
			if (X[i] * Y[j] - X[j] * Y[i] > 0) {
				x += X[j];
				y += Y[j];
			}
			else if (X[i] * Y[j] - X[j] * Y[i] == 0 && X[i] * X[j] >= 0 && Y[i] * Y[j] >= 0) {
				x += X[j];
				y += Y[j];
			}
		}
		kotae = max(kotae, sqrt(x * x + y * y));
		x = 0;
		y = 0;
		rep(j, N) {
			if (X[i] * Y[j] - X[j] * Y[i] < 0) {
				x += X[j];
				y += Y[j];
			}
			else if (X[i] * Y[j] - X[j] * Y[i] == 0 && X[i] * X[j] >= 0 && Y[i] * Y[j] >= 0) {
				x += X[j];
				y += Y[j];
			}
		}
		kotae = max(kotae, sqrt(x * x + y * y));
		x = 0;
		y = 0;
		rep(j, N) {
			if (X[i] * Y[j] - X[j] * Y[i] > 0) {
				x += X[j];
				y += Y[j];
			}
		}
		kotae = max(kotae, sqrt(x * x + y * y));
		x = 0;
		y = 0;
		rep(j, N) {
			if (X[i] * Y[j] - X[j] * Y[i] < 0) {
				x += X[j];
				y += Y[j];
			}
		}
		kotae = max(kotae, sqrt(x * x + y * y));
	}

	cout << setprecision(12) << kotae << endl;


	Would you please return 0;
}
