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
	//ll tx = engine[angle[0].second].first, ty = engine[angle[0].second].second;
	/*
	double ans = sqrt(tx * tx + ty * ty);
	int r = 1;
	
	for (int l = 0; l < 2 * N; l++) {
		//[l, r)の番目のものをしゃくとり
		ans = max(ans, sqrt(tx * tx + ty * ty));
		while (r < 2 * N && r - l < N && 
			ans <= 
			sqrt(pow(tx + engine[angle[r % N].second].first, 2) + pow(ty + engine[angle[r % N].second].second, 2))
			+ EPS) {
			tx += engine[angle[r % N].second].first, ty += engine[angle[r % N].second].second;
			r++;
			ans = max(ans, sqrt(tx * tx + ty * ty));
		}
		ans = max(ans, sqrt(tx * tx + ty * ty));

		if (l == r)r++;
		else {
			tx -= engine[angle[l % N].second].first, ty -= engine[angle[l % N].second].second;
			ans = max(ans, sqrt(tx * tx + ty * ty));
		}
	}*/

	double ans = 0;
	for (int i = 0; i < N; i++) {
		ll tx = engine[angle[i].second].first, ty = engine[angle[i].second].second;
		ans = max(ans, sqrt(tx*tx + ty*ty));
		for (int j = i + 1; j < N + i; j++) {
			int k = j % N;
			tx += engine[angle[k].second].first, ty += engine[angle[k].second].second;
			ans = max(ans, sqrt(tx*tx + ty*ty));
		}
	}

	cout << setprecision(12) << ans << endl;
	return 0;
}