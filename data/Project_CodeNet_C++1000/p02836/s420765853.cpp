#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	string S;
	cin >> S;
	int N = S.size();
	N = N/2;
	int ans = 0;
	rep(i, N){
		if (S[i] != S[S.size()-i-1]) ans++;
	}
	cout << ans << endl;
	return 0;
}
