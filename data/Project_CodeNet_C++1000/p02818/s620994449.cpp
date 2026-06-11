#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	LL a,b,k;
	// nyuryoku
	cin >> a >> b >> k;
	// keisan
	if(a+b <= k){
		cout << '0' << ' ' << '0' << endl;
		return 0;
	}
	if(a >= k){
		cout << a-k << ' ' << b << endl;
		return 0;
	}
	cout << '0' << ' ' << b-(k-a) << endl;
	// syutsuryoku
}