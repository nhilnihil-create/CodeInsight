#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;

int main(){
	cin >> N;

	long long ans = LONG_MAX;
	for(long long i = 1; i * i <= N; i++) {
		if(N%i == 0) {
			ans = min(ans, i - 1 + N/i - 1);
		}
	}
	cout << ans << endl;
}

