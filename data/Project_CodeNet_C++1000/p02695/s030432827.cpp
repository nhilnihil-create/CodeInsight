#include<bits/stdc++.h>
using namespace std;

long long N, M, Q;

long long ans[15];

long long a[55];
long long b[55];
long long c[55];
long long d[55];

long long maxi;

long long dfs(long long pa, long long dep) {
	if(dep == N) {
		long long tmp = 0;
		for(long long i = 0; i < Q; i++) {
			if(ans[b[i]] - ans[a[i]] == c[i]) {
				tmp += d[i];
			}
		}
		maxi = max(maxi, tmp);
		return 0;
	}

	for(int i = pa; i <= M; i++) {
		ans[dep] = i;
		dfs(i, dep+1);
	}
	return 0;
}


int main(){
	cin >> N >> M >> Q;

	for(long long i = 0; i < Q; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--;b[i]--;
	}

	dfs(1, 0);
	cout << maxi << endl;
	return 0;
}