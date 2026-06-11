#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7 ;
LL ans[ 2020 ] , n;
void ditui(){
	ans[5] = 1 ;ans[6] = 2 ; ans[7] = 3 ;
	for (LL i = 8;i <= n;i ++){
		ans[i] = ans[i - 1] + ans[i - 3] ;
		ans[i] %= MOD;
	}
}
int main(){
	cin >> n ;
	if ( n <= 2 ){
		cout << "0" << '\n' ;
		return 0;
	}
	if (n == 3 || n == 4){
		cout << "1" << '\n' ;
		return 0;
	}
	ditui();
	cout << ans[n] % MOD << endl;
	return 0;
}