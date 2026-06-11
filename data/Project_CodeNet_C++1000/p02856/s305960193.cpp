//q099.cpp
//Fri Sep 18 22:19:51 2020

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
	int m;
	cin >> m;

	ll D=0;
	ll S=0;
	rep(i,m){
		ll d,c;
		cin >> d >> c;
		D+=c;
		S+=d*c;
	}

	cout << D-1+(S-1)/9 << endl;
//	printf("%.4f\n",ans);
}