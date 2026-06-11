//msol2020_d.cpp
//Sun Aug  2 20:38:37 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n;
	cin >> n;

	ll a[n];
	rep(i,n) cin >> a[i];

	ll ans = 1000;
	ll kabu = 0;
	for (int i=0;i<n-1;i++){
		if(kabu==0 && a[i+1]>a[i]){
			kabu = ans/a[i];
			ans = ans%a[i];
		}else if (kabu>0 && a[i+1]<a[i]){
			ans = ans + a[i]*kabu;
			kabu = 0;
		}
		// cout << ans << endl;
	}
	if (kabu>0){
		ans += a[n-1]*kabu;
	}

	cout << ans << endl;
}