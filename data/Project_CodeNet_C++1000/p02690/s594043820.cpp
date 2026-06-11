#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power (ll base , ll pow){
	if (pow == 0){
		return 1;
	}
	ll temp = power(base , pow/2);
	if (pow % 2 == 1){
		return temp * temp * base;
	} else {
		return temp * temp;
	}
}

int main(){
	ll x;
	cin >> x;

	bool done = false;
	for(ll i = -125 ; i <126 ; i++){
		for(ll j = -125 ; j <126 ; j++){
			ll a = power(i , 5);
			ll b = power(j , 5);

			ll temp = a - b;
			if (temp == x){
				cout << i << " " << j << endl;
				done = true;
				break;
			}
		}
		if (done){break;}
	}

	return 0;
}
