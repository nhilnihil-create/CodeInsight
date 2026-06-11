#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int B[N-1];
	rep(i,N-1) cin >> B[i];
	int ans = B[N-2] + B[0];
	for (int i = 0; i <= N-3; i++) {
		ans += min(B[i],B[i+1]);
	}
	cout << ans << endl;
	return 0;
}
