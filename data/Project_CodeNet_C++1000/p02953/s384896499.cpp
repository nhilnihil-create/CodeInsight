#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	ll H[N];
	rep(i,N) cin >> H[i];

	for (int i = N-2; i >=0; i--) {
		if (H[i]-H[i+1] == 1) H[i]--;	
		if (H[i]-H[i+1] > 1) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	return 0;
}
