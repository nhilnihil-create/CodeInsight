#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N;
	cin >> N;
	int v[N];
	rep(i,N) cin >> v[i];
	sort(v,v+N);
	double ans = v[0];
	for (int i = 1; i <= N-1; i++) {
		ans = 0.5*(ans + v[i]);
	}
	cout << ans << endl;


	return 0;
}
