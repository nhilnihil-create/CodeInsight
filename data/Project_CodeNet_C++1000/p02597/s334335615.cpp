//abc174_d.cpp
//Sat Sep 12 10:35:13 2020

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
	int n;
	cin >> n;
	string s;
	cin >> s;

	ll rnum = 0;
	rep(i,n){
		if (s[i]=='R'){
			rnum++;
		}
	}
	ll ans = 0;
	rep(i,rnum){
		if (s[i]=='W'){
			ans++;
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}