#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N;
	ll K;
	cin >> N >> K;
	int A[N+1];
	rep(i,N) cin >> A[i+1];

	int vis[N+1], step[N+1];
	rep(i,N) vis[i+1] = 0;
	int k = 1;
	int i_loop = N;
	for (int i = 0; i <= N; i++) {
		vis[k]++;
		if (vis[k] == 2) {
			i_loop = i;
			break;
		}
		step[k] = i;
		k = A[k];	
	}

	if (K <= step[k]) {
		int goal = 1;
		rep(i,K){
			goal = A[goal];
		}
		cout << goal << endl;
		return 0;
	}

	int T = i_loop - step[k];
	vector<int> ltown;
	rep(i,T){
		ltown.push_back(k);
		k = A[k];
	}

	K -= step[k];
	K %= T;
	cout << ltown[K] << endl;
	
	
return 0;
}
