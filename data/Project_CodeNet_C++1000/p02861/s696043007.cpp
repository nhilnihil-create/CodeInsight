//q015.cpp
//Sun Aug  9 12:40:42 2020

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
typedef pair<double,double> P;

int main(){
	int n;
	cin >> n;

	P p[n];
	rep(i,n) {
		double x,y;
		cin >> x >> y;
		p[i].first = x;
		p[i].second = y;
	}

	double ans = 0;
	sort(p,p+n);
	do {
		double tmp = 0;
		for (int i=1;i<n;i++){
			tmp += sqrt((p[i].first-p[i-1].first)*(p[i].first-p[i-1].first)+
		(p[i].second-p[i-1].second)*(p[i].second-p[i-1].second));
		}
		ans += tmp;
	} while (next_permutation(p,p+n));

	for (int i=1;i<=n;i++){
		ans = ans/double(i);
	}

	printf("%.10f\n",ans);
}