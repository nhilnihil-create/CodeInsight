#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	double p[N];
	double sum[N+1];
	for(int i=0;i<N;i++){
		cin >> p[i];
	}
	sum[0] = 0;
	for(int i=1;i<N+1;i++){
		sum[i] = sum[i-1] + p[i-1];
	}
	double ans = 0.0;
	for(int i=0;i<=N-K;i++){
		ans = max(ans, (sum[i+K] - sum[i] + K) / 2);
	}
	printf("%.12f\n", ans);
}