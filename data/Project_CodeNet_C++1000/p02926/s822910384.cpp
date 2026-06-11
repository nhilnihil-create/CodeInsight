#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

const int hoken = 10;

const double EPS = 1e-9;
const double PI = acos(-1);

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, int> AngleP;

int main() {
	int N;
	P engine[100 + hoken];
	AngleP angle[100 + hoken];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> engine[i].first >> engine[i].second;
		if (abs(engine[i].first) < EPS && abs(engine[i].second) < EPS) {
			angle[i].second = i, angle[i].first = 0;
		}
		else {
			angle[i].second = i, angle[i].first = atan2(engine[i].second, engine[i].first);
		}
	}
	sort(angle, angle + N);
	ll tx = 0, ty = 0;
	
	double ans = 0;
	double cur = 0;
	int r = 0;
	
	for (int l = 0; l < 2 * N; l++) {
		ans = max(ans, sqrt(tx * tx + ty * ty));
		while (r <= 2 * N && r - l < N &&
			sqrt(tx * tx + ty * ty) < EPS + sqrt(pow(tx + engine[angle[r % N].second].first, 2)
				+ pow(ty + engine[angle[r % N].second].second, 2))) {
			tx += engine[angle[r % N].second].first;
			ty += engine[angle[r % N].second].second;
			ans = max(ans, sqrt(tx*tx + ty*ty));
			r++;
		}
		ans = max(ans, sqrt(tx*tx + ty*ty));
		if (l == r) {
			r++;
		}
		else {
			tx -= engine[angle[l % N].second].first;
			ty -= engine[angle[l % N].second].second;
			ans = max(ans, sqrt(tx*tx + ty*ty));
		}
	}

	cout << setprecision(12) << ans << endl;
	return 0;
}