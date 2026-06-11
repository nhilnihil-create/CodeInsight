#include <bits/stdc++.h>
using namespace std;
int main(){
	long N;
	cin >> N;
	long A[N], cnt[N+1];
	long ans = 0;
	for(long i=0;i<N+1;i++){
		cnt[i] = 0;
	}
	for(long i=0;i<N;i++){
		cin >> A[i];
		cnt[A[i]]++;
	}

	for(long j=0;j<N+1;j++){
		ans += cnt[j] * (cnt[j] - 1) / 2;
	}
	for(long i=0;i<N;i++){
		long tmp = ans;
		tmp -= cnt[A[i]] * (cnt[A[i]] - 1) / 2;
		tmp += (cnt[A[i]] - 1) * (cnt[A[i]] - 2) / 2;
		cout << tmp << endl;
	}
}
