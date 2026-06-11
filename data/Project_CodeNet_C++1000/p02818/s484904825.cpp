#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	ll A, B, K;
	cin >> A >> B >> K;
	ll takahashi;
	ll aoki;
	if (K <= A) {
		takahashi = A - K;
		aoki = B;
	}
	else if (K <= A + B) {
		takahashi = 0;
		aoki = B - (K - A);
	}
	else{
		takahashi = 0;
		aoki = 0;
	
	}
	cout << takahashi << " " << aoki << endl;
	//cout << ans << endl;
	return 0;
}
