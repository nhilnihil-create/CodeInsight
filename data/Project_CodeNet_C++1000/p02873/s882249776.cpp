#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	string s;
	cin >> s;
	vector<ll>arr(s.size() + 1);
	rep(i, s.size() + 1) {
		if (i == 0)arr[i] = (s[i] == '<') ? 0LL : 1LL;
		else if (i == s.size())arr[i] = (s[i-1] == '>') ? 0 : arr[i - 1] +1LL;
		else {
			if (s[i - 1] == '>' && s[i] == '<')arr[i] = 0;
			else if (s[i - 1] == '<')arr[i] = arr[i - 1] + 1LL;
		}
	}

	for (ll i = s.size()-1; i >=0;i--) {
		if (s[i] == '>')arr[i] = max(arr[i + 1] + 1LL,arr[i]);
	}
	if (s[0] == '>')arr[0] = arr[1] + 1LL;

	ll sum = accumulate(all(arr),0LL);
	cout << sum << endl;
}
