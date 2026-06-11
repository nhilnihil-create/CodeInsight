#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1000000007;

/*
  dp1[i+1] : a+bが、Lの上からi桁と等しい組み合わせの数
  dp2[i+1] : a+bが、Lの上からi桁より小さい組み合わせの数
  
*/

ll dp1[100005];
ll dp2[100005];

int main(){
	string L;
	cin >> L;
	
	ll sum = 0;
	dp1[0] = 1;
	dp2[0] = 0;
	
	for ( size_t i = 0; i < L.size(); i++ ){
		if ( L[i] == '0' ){
			dp1[i+1] = dp1[i];
			dp2[i+1] = dp2[i]*3 % MOD;
		}
		else {
			dp1[i+1] = dp1[i]*2 % MOD;
			dp2[i+1] = (dp2[i]*3+dp1[i]) % MOD;
		}
		
		//cout << dp1[i+1] << "     " << dp2[i+1] << endl;
	}
	
	cout << (dp1[L.size()]+dp2[L.size()])%MOD << endl;
	
	return 0;
}

