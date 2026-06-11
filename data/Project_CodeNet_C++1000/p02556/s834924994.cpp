//abc178_e.cpp
//Sun Sep 13 20:42:27 2020

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
typedef pair<ll,ll> P;

int main(){
	int n;
	cin >> n;

	vector<ll> zx,zy;
	rep(i,n) {
		ll x,y;
		cin >> x >> y;
		zx.push_back(x+y);
		zy.push_back(x-y);
	}

	sort(zx.begin(),zx.end());
	sort(zy.begin(),zy.end());

	ll ans = max(zx[zx.size()-1]-zx[0],zy[zy.size()-1]-zy[0]);
	cout << ans << endl;

}
