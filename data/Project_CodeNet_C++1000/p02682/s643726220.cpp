#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	ll a, b, c, k, sum = 0;
	cin >> a >> b >> c >> k;
	
	if ( a <= k ){
		sum += a;
		k -= a;
	}
	else if ( a > k ){
		sum += k;
		k = 0;
	}
	if ( b <= k ){
		sum += b * 0;
		k -= b;
	}
	else if ( b > k ){
		sum += 0 * k;
		k = 0;
	}
	if ( c <= k ){
		sum += (c * -1);
		k -= c;
	}
	else if ( c > k ){
		sum += (k * -1);
		k = 0;
	}
	cout << sum << endl;
	return 0;
}