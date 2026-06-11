#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	ll ans = 0;
	int now = 0;
	int g = 0;
	int l = 0;
	rep(i,S.size()) {
		if (S[i] == '<') {
			now++;
			g = now;
			ans += now;
		}
		else {
			if (now == 0) l++;
			else l = 0;
			if (g==l) {
				g++;
				ans++;
			}
			now = 0;
			ans += l;
		}
	}
	cout << ans << endl;
	return 0;
}
