#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11

using namespace std;

long long N;
long long d[105];
int main(){
	cin >> N;
	rep(i, N) cin >> d[i];
	long long ans = 0;
  // 組み合わせの実装
	for(long long i = 0; i < N; i++) {
		for(long long j = i + 1; j < N; j++) {
			ans += d[i] * d[j];
		}
	}
	cout << ans << endl;
}
