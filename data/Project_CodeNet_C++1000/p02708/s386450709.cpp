#include<bits/stdc++.h>
using namespace std;

#define DIV 1000000007

long long N, K;
long long mini[200005];
long long maxi[200005];

int main(){
	cin >> N >> K;


	for(long long i = 0; i < N+1; i++) {
		mini[i+1] = i + mini[i];
		mini[i+1]%=DIV;
	}

	for(long long i = 0; i < N+1; i++) {
		maxi[i+1] = (N - i) + maxi[i];
		maxi[i+1]%=DIV;
	}



	long long ans = 0;
	for(long long num = K; num <= N+1; num++) {
		ans += maxi[num] - mini[num] + 1;
		ans = (ans + DIV)%DIV;

	}
	cout << ans << endl;
}
