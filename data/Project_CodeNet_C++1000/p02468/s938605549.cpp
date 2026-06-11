
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define l long long
using namespace std;
const l mod = 1000000007;

l my_pow(l m, int n){
	l res = 1;
	while(n>0){
	if(n&1)res = m*res % mod;
		n >>= 1;
		m = m*m % mod;
	}
	return res;
}
int main(){
	int m,n;
	cin >> m >> n;
	cout << my_pow(m,n) % mod<< endl;
	return 0;
}