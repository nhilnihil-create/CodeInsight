//sppsfver - 20.08.2020
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair <ll, ll>;
const int MAX = 1e5+5;

ll n, r, w, ans;
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (auto x : s){
		x == 'R' ? r++ : w++;
	}
	for (int i = n-w; i < n; i++){
		ans += (s[i] == 'R');
	}
	cout << ans << endl;
	return 0;
}
