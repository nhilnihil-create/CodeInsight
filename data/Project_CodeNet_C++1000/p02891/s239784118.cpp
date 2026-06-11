#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	ll K;
	cin >> S >> K;
	ll ans = 0;
	string A = "", B="";
	int i = 1;
	A += S[0];
	while (i<S.size() ) {
		if (S[i] != S[0]) break;
		A += S[i];
		i++;
	}
	while (i<S.size() ) {
		B += S[i];
		i++;
	}
	B += A;
	char now = B[0];
	ll cnt = 1;
	for (int i = 1; i < B.size(); i++) {
		if (B[i] == now)	cnt++;
		else {
			ans += (cnt/2)*K;
			cnt = 1;
			now = B[i];
		}
	}
	ans += (cnt/2)*(K-1);
	ll p = cnt - A.size();
	ans += (p/2) + A.size()/2;

	if (B.size() == A.size()) ans = (K*B.size())/2;

	cout << ans << endl;
	return 0;
}
