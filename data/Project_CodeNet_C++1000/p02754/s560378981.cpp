#include <bits/stdc++.h>
using namespace std;
int main(){
	long long N, A, B;
	cin >> N >> A >> B;
	long long ans = 0;
	long long AB = A + B;
	ans += (N / AB) * A;
	N %= AB;
	if(N < A)ans += N;
	else ans += A;
	cout << ans << endl;
}
