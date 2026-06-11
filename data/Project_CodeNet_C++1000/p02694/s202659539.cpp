#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
	int x;
	cin >> x;
	__int128 n = 100;
	int ans = 0;
	while(n < x){
		ans += 1;
		n = (n*101/100);
	}

	cout << ans << endl;

	return 0;
}
