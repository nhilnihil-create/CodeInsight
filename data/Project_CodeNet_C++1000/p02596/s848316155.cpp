//abc174_c.cpp
//Sat Sep 12 10:35:04 2020

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
	int k;
	cin >> k;

	if (k%2==0){
		cout << -1 << endl;
		return 0;
	}

	ll tmp = 7;
	ll ans = 1;
	while(1){
		if (tmp%k!=0){
			tmp = tmp%k;
			tmp = tmp*10+7;
			ans++;
		}else {
			cout << ans << endl;
			return 0;
		}
		if (ans >= 1e7){
			cout << -1 << endl;
			return 0;
		}
	}

}