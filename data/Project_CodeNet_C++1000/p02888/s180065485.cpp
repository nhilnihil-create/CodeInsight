#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int L[N];
	vector<int> a(2005);
	rep(i,N) {
		cin >> L[i];
		a[L[i]]++;
	}
	sort(L,L+N);
	rep(i,2005) a[i+1] += a[i];
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			ans += a[L[i]+L[j]-1] - (j+1);
		}
	}
	cout << ans << endl;

	return 0;
}
