#include<bits/stdc++.h>
using namespace std;

int main(){
	// sengen
	long long n,k,sum,wari;
	// nyuryoku
	cin >> n >> k;
	// keisan
	wari = 1000000007;
	sum = 0;
	for(long long i=k;i<=n+1;i++){
		sum += i*(2*n-i+1)/2 - i*(i-1)/2 +1;
		sum = sum%wari;
	}
	// syutsuryoku
	cout << sum;
}