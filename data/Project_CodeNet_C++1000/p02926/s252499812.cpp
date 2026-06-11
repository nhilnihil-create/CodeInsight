#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
typedef pair<double, int> P;
ll X[100], Y[100];
int main() {
	int N;
	cin >> N;
	vector<P> vec;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		vec.emplace_back(atan2(Y[i], X[i]), i);
	}
	sort(vec.begin(), vec.end());
	vector<P> vec2 = vec;
	vec2.insert(vec2.end(), vec.begin(), vec.end());
	double ans = 0;
	for (int i = 0; i < vec2.size(); i++) {
		for (int j = i; j < vec2.size(); j++) {
			if (j - i + 1 > N) break;
			ll sumX = 0, sumY = 0;
			for (int k = i; k <= j; k++) {
				sumX += X[vec2[k].second];
				sumY += Y[vec2[k].second];
			}
			ans = max(ans, sqrt(sumX*sumX + sumY * sumY));
		}
	}
	printf("%.15lf\n", ans);
}
