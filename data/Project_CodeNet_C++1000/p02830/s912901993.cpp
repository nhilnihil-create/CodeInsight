#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int N;
	cin >> N;
	string S, T;
	cin >> S >> T;
	rep(i, N){
		cout << S[i] << T[i];
	}
	cout << endl;
	//cout << ans << endl;
	return 0;
}
