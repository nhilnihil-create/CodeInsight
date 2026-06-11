#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	ll N, K;
	cin >> N >> K;
	if (K<=N) N = N%K;
	N = min(N,K-N);
	cout << N << endl;
	return 0;
}
