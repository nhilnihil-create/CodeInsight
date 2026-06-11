#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	map<ll, ll> a,b;
	ll in;
	REP(i,n){
		cin >> in;
		a[i+1+in]++;
		b[i+1-in]++;
	}
	ll ans=0;
	for(auto x: a){
		ans += x.second*b[x.first];
	}
	
	cout << ans << endl;
	
	
	return 0;
}