#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int N, i, j;
	scanf("%lld", &N);
	vector<pair<int, int>> ps(N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &ps[i].first, &ps[i].second);
	}
	auto comp = [&](pair<int, int> a, pair<int, int> b){
		return atan2(a.first, a.second) < atan2(b.first, b.second);
	};
	sort(ps.begin(), ps.end(), comp);
	int ans = 0;
	for(i = 0; i < N; i++){
		int X = 0, Y = 0;
		for(j = 0; j < N; j++){
			X += ps[(i + j) % N].first;
			Y += ps[(i + j) % N].second;
			ans = max(ans, X * X + Y * Y);
		}
	}
	printf("%.20lf\n", sqrt(double(ans)));
	return 0;
}