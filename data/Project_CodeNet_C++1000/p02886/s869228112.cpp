#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0; i<n; i++)
		cin >> a[i];
	ll ans = 0;
	for(ll i=0; i<n; i++){
		for(ll j=i+1; j<n; j++){
			ans += a[i]*a[j];
		}
	}
	cout << ans;
	return 0;
}