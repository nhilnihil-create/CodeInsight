#include<bits/stdc++.h>
using namespace std;

long long N, M, X;
long long C[20];
long long A[20][20];

int main(){
	cin >> N >> M >> X;
	for(long long i = 0; i < N; i++) {
		cin >> C[i];
		for(long long j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}


	long long ans = LONG_MAX;
	for(long long pat = 0; pat < (1<<N); pat++) {
		vector<long long> rikai(20);
		long long cost = 0;
		for(long long idx = 0; idx < N; idx++) {
			//idx版目の教科書を読む
			if((pat>>idx)&1) {
				cost += C[idx];
				for(long long kamoku = 0; kamoku < M; kamoku++) {
					rikai[kamoku] += A[idx][kamoku];
				}
			}
		}

		bool ok = true;
		for(long long kamoku = 0; kamoku < M; kamoku++) {
			if(rikai[kamoku] < X) {
				ok = false;
			}
		}
		if(ok) {
			ans = min(ans, cost);
		}
	}
	if(ans == LONG_MAX) {
		cout << -1 << endl;
	}else{
	cout << ans << endl;
	}
}

