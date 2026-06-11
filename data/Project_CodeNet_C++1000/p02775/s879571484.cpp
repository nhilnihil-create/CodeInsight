#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const ll inf = 2e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;
	int ans = 0, carry = 0;
	for(int i = (int)s.length() - 1; i >= 0; i--) {
		int cur = (s[i] - '0') + carry;
		if(cur < 5) {
			ans += cur;
			carry = 0;
		}
		else if(cur == 5) {
			ans += cur;
			if((i - 1 >= 0 && s[i - 1] <= '4') || (i == 0)) {
				carry = 0;
			}
			else {
				carry = 1;
			}
		}
		else {
			ans += (10 - cur);
			carry = 1;
		}
	}
	if(carry) {
		ans++;
	}
	cout << ans;

	return 0;
}