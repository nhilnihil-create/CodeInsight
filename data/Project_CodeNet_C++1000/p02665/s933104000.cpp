//nomura2020_c.cpp
//Sat Jun 27 18:12:55 2020

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

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n;
	cin >> n;

	ll a[n+1];
	for (int i=0;i<=n;i++){
		cin >> a[i];
	}

	if (n!=0 && a[0] != 0){
		cout << -1 << endl;
		return 0;
	}else if (n==0 && a[0] == 1){
		cout << 1 << endl;
		return 0;
	}else if (n==0 && a[0] != 1){
		cout << -1 << endl;
		return 0;
	}

	ll asum[n+1];
	asum[n] = a[n];
	for (int i=n-1;i>=0;i--){
		asum[i] = asum[i+1]+a[i];
	}

	ll ans = 1;
	ll kotsuki = 1;
	for (int i=1;i<=n;i++){
		ll max1 = kotsuki*2;
		ll max2 = asum[i];
		ll max = min(max1,max2);
		// cout << i << " " << max << endl;
		if (i!=n && max<=a[i]){
			cout << -1 << endl;
			return 0;
		}else if (i==n && max<a[i]){
			cout << -1 << endl;
			return 0;
		}
		ans += max;
		kotsuki = max-a[i];
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}