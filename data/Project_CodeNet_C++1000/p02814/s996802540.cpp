//q097.cpp
//Tue Sep 15 22:34:16 2020

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
	ll n,m;
	cin >> n >> m;

	ll logtwo = -1;
	ll x;
	rep(i,n){
		ll tmp;
		cin >> tmp;
		tmp = tmp/2;
		if (logtwo==-1){
			ll z = tmp;
			ll c = 0;
			while(z%2==0){
				c++;
				z = z/2;
			}
			logtwo = c;
			x = tmp;
		}else {
			ll z = tmp;
			ll c = 0;
			while(z%2==0){
				c++;
				z = z/2;
			}
			if (logtwo != c){
				cout << 0 << endl;
				return 0;
			}else {
				x = lcm(x,tmp);
				if (x>m){
					cout << 0 << endl;
					return 0;
				}
			}
		}
	}
	if (x>m){
		cout << 0 << endl;
	}else {
		cout << (m-x)/(x*2)+1 << endl;
	}
//	printf("%.4f\n",ans);
}