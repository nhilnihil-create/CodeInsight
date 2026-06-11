#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;
const int inf = 99999999;

using namespace std;

const ll mod = 1e9 + 7;

int main(){
	ll n;
	cin >> n;
	if(n % 2 == 1 || n < 10){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	ll i = 5;
	while(i <= n){
		ll p = (n / i);
		ans += (p / 2);
		i *= 5;
	}
	cout << ans << endl;
	return 0;
}
 
