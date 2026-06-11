#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N, M;
	cin >> N >> M;

	vector <pair<ll, ll>> C;
	for (int ii = 0; ii < N; ++ii){
		ll A, B;
		cin >> A >> B;
		C.push_back(make_pair(A, B));
	}
	sort(C.begin(), C.end());	//時間が短い順に並んでいる

	ll idx = 0;
	ll ans = 0;
	priority_queue<ll> q;
	for (int ii = M-1; ii >= 0; --ii){
		ll aa = M - ii;
		while(aa == C[idx].first) {
			q.push(C[idx].second);
			idx++;
			if (idx == N) break;
		}
		if (!q.empty()){
			ans += q.top();
			q.pop();
		}
	}

	cout << ans << "\n";


	return 0;
}
