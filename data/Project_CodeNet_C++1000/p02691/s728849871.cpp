#include<bits/stdc++.h>
using namespace std;

long long N;
long long A[200005];

int main(){
	cin >> N;

	for(long long i = 0; i < N; i++) {
		cin >> A[i];
	}

	long long ans = 0;
	map<long long, long long> zero;
	for(long long i = 0; i < N; i++) {
		long long leftzero = i - A[i];
		long long rightzero = i + A[i];

		if(zero.count(leftzero))
			ans += zero[leftzero];

		zero[rightzero] += 1;
	}
	cout << ans << endl;
}