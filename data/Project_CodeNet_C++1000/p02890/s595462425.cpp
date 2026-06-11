#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
#define MOD 1000000007
#define tp tuple<ll,ll,ll>

int ans[300010];

int main() {
	for (int i = 0;i < 300010;i++)ans[i] = 0;
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
	int xs, ot;
	for (int i = 1;i <= N;i++) {
		auto it = lower_bound(all(S), i);
		xs = it - S.begin();
		if (xs == 0) {
			ans[ss] = i;//最大幅
		}
		else {
			ot = ss - xs;
			ans[T[xs - 1] / i + ot] = i;
		}
	}
	for (int i = N;i > 0;i--) {
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for (int i = 1;i <= N;i++) {
		cout << ans[i] << endl;
	}
}