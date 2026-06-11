//abc174_b.cpp
//Sat Sep 12 10:34:52 2020

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
	ll n,d;
	cin >> n >> d;

	ll x[n],y[n];
	ll ans = 0;
	rep(i,n){
		cin >> x[i] >> y[i];
		if (sqrt(x[i]*x[i]+y[i]*y[i])<=d){
			ans++;
		}
	} 

	cout << ans << endl;
//	printf("%.4f\n",ans);
}