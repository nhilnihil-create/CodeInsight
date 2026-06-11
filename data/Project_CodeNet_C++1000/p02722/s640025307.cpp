#include<bits/stdc++.h>
using namespace std;

long long N;

bool check(long long n, long long k) {
	if(n == 1) {
		return true;
	}
	if(n<k) {
		return false;
	}
	if(n%k == 0) {
		return check(n/k, k);
	} else {
		if(n%k == 1) {
			return true;
		}
		return false;
	}
}

int main(){
	cin >> N;

	long long ans = 0;
	for(long long i = 2; i * i <= N; i++) {
		if(N%i == 0) {
			if(check(N, i)) {
				ans++;
			}
			if(i != N/i && check(N, N/i)){
				ans++;
			}
		}
	}

	//K = N
	ans++;


	N--;
	for(long long i = 2; i * i <= N; i++) {
		if(N%i == 0) {
			if(check(N+1, i)) {
				ans++;
			}
			if(i != N/i && check(N+1, N/i)){
				ans++;
			}
		}
	}
	//K = N - 1
	if(N!=1){
	ans++;
	}

	cout << ans << endl;


}
