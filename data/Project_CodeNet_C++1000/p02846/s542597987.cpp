#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll t1,t2,a1,a2,b1,b2;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	a1 *= t1;
	a2 *= t2;
	b1 *= t1;
	b2 *= t2;
	if((a1 + a2) < (b1 + b2)){
		swap(a1,b1);
		swap(a2,b2);
	}
	ll c1,c2;
	c1 = a1 - b1;
	c2 = a2 - b2;
	if(c1 + c2 == 0){
		cout << "infinity" << endl;
	}
	else if(c1 > 0){
		cout << 0 << endl;
	}
	else{
		ll sum = 0;
		if(c1 < 0)
			sum--;
		sum += c2 / (c1 + c2) * 2;	
		if(c2 % (c1 + c2) == 0)
			sum--;
		cout << sum << endl;
	}
	return 0;
}