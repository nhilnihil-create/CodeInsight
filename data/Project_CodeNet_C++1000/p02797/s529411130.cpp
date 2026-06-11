#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, K, S;
	cin >> N >> K >> S;
	vector<int> v;
	rep(i,K) v.push_back(S);
	if (S == 1e9) {
		rep(i,N-K) v.push_back(1);
	}
	else {
		rep(i,N-K) v.push_back(S+1);
	}
	rep(i,N) cout << v[i] << endl;
	return 0;
}
