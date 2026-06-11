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

using namespace std;

int main(){
	
	ll n , m , k;
	cin >> n >> m >> k;
	vector<ll> a(n + 1 , 0) , b(m + 1, 0);
	
	for(ll i = 1; i <= n; i++){
		ll input;
		cin >> input;
		a[i] = input + a[i - 1];
	}
	
	for(ll i = 1; i <= m; i++){
		ll input;
		cin >> input;
		b[i] = input + b[i - 1];
	}
	
	ll ans = 0;
	ll mx = m;
	for(ll i = 0; i <= n; i++){
		if(a[i] > k)break;
		while(b[mx] + a[i] > k){
			mx--;
		}
		ans = max(ans , i + mx);
	}
	cout << ans << endl;		
	
	return 0;
}
 
