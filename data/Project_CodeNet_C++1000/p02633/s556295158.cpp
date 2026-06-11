//agc046_a.cpp
//Sat Jul 11 10:01:31 2020

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

//最大公倍数、最大公約数（ユークリッド互除法）
ll gcd (ll a, ll b){ //最大公約数
	if (b == 0){
		return a;
	}
	return gcd(b, a%b);
}

ll lcm (ll a, ll b){ //最小公倍数
	ll temp = gcd(a,b);
	return (a/temp)*b;
}


int main(){
	int n;
	cin >> n;

	int ans = lcm(n,360);


	cout << ans/n << endl;
//	printf("%.4f\n",ans);
}