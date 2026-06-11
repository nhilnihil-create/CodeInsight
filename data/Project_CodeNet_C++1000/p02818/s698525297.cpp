//q095.cpp
//Tue Sep 15 20:18:23 2020

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
	ll a,b,k;
	cin >> a >> b >> k;

	if (a>=k){
		cout << a-k << " " << b << endl;
	}else if (a+b>=k){
		cout << 0 << " " << a+b-k << endl;
	}else {
		cout << 0 << " " << 0 <<  endl;
	}
}