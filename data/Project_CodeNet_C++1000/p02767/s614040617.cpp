#include<bits/stdc++.h>
using namespace std;

long long N;
long long X[105];

int main(){
	cin >> N;
	for(long long i = 0; i < N; i++) {
		cin >> X[i];
	}

	long long ans = LONG_MAX;

	for(long long i = 0; i < 105; i++) {
		long long tmp = 0;
		for(long long j = 0; j < N; j++) {
			tmp += (i - X[j]) * (i - X[j]);
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}