#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int P[N];
	rep(i,N) cin >> P[i];

	int Q[N];
	int minl = P[0];
	rep(i,N){
		minl = min(minl,P[i]);
		Q[i] = minl;
	}
	int ans = 0;
	rep(i,N){
		if (Q[i]>=P[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}
