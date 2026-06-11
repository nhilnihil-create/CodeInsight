#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
#define MOD 1000000007
#define tp tuple<ll,ll,ll>

int main() {
	int N, A;
	cin >> N;
	map<ll, ll> M;
	for (int i = 0;i < N;i++) {
		cin >> A;
		if (M.count(A))M[A]++;
		else M.insert({ A,1 });
	}
	vector<int> S;
	for (auto x : M) {
		S.push_back(x.second);
	}
	
	int ss = S.size();
	sort(all(S));
	vector<int> T = S;
	for (int i = 1;i < ss;i++) {
		T[i] += T[i - 1];
	}
	int ok, ng, mid, xs, ot, ans;
	cout << N << endl;
	for (int i = 2;i <= N;i++) {
		ok = 0, ng = N + 1;
		if (ss < i) {
			cout << 0 << endl;
			continue;
		}
		while (ok + 1 != ng) {
			mid = (ok + ng) / 2;
			auto it = lower_bound(all(S), mid);
			xs = it - S.begin();
			if (xs == 0) {
				ans = ss;//最大幅
			}
			else {
				ot = ss - xs;
				//cout << ss << " " << xs << " ";
				ans = T[xs - 1] / mid + ot;
			}
			//cout << i << " " << mid << " " << ans << endl;
			if (ans >= i) {
				ok = mid;
			}
			else {
				ng = mid;
			}
		}
		cout << ok << endl;
	}
}