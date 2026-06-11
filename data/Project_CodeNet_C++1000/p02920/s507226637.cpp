#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 4e5 + 4433, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define left defnotavariable
int n;
multiset<int> left;
vi used;
void apply() {
	for(int i = used.size(); i--;) {
		auto it = left.upper_bound(used[i]-1);
		if(it==left.begin()) {cout << "No"; exit(0);}
		--it;
		used.pb(*it);
		left.erase(it);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int t, i = 0; i < 1<<n; i++) cin >> t, left.insert(t);
	used.pb(*left.rbegin());
	left.erase(--left.end());
	while(left.size())
		apply();
	cout << "Yes";
}

