//q015.cpp
//Thu Sep 24 21:38:09 2020

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

	P a[n];
	rep(i,n){
		double x,y;
		cin >> x >> y;
		a[i] = P(x,y);
	}

	sort(a,a+n);
	double ans = 0;
	double count = 0;
	do{
		rep(i,n-1){
			ans+=sqrt((a[i+1].first-a[i].first)*(a[i+1].first-a[i].first)+(a[i+1].second-a[i].second)*(a[i+1].second-a[i].second));
		}
		count++;
	}while(next_permutation(a,a+n));

	ans = ans/count;
	printf("%.10f\n",ans);
}