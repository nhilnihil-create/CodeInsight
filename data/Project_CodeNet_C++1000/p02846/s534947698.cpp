#include <iostream>
#include <cmath>
using namespace std;
using LL = long long;
int main(){
	//freopen("test", "r", stdin);
	ios::sync_with_stdio(false);
	LL T1, T2;
	cin >> T1 >> T2;
	LL A1, A2, B1, B2;
	cin >> A1 >> A2 >> B1 >> B2;
	if(A1 - B1 > 0) swap(A1, B1), swap(A2, B2);
	LL dif1 = T1 * (A1 - B1), dif2 = T2 * (A2 - B2);
	if(dif1 + dif2 < 0){
		cout << "0";	
	}else if(dif1 + dif2 == 0){
		cout << "infinity";
	}else{
		if(2 * dif1 + dif2 > 0){
			cout << "1";
		}else if(2 * dif1 + dif2 == 0){
			cout << "2";	
		}else{
			LL tmp = 2 * dif1 + dif2 - dif1;
			LL tot = -dif1 / tmp;
			cout << tot * 2 + ((dif1 % tmp == 0)? 0: 1);
		}
	}
	return 0;
}
