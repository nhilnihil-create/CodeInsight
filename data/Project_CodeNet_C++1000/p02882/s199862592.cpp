//q091.cpp
//Sun Sep 13 12:15:04 2020

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
	double a,b,x;
	cin >> a >> b >> x;

	double tmp = x/a;
	if (a*b/2>=tmp){
		double c = tmp*2/b;
		double d = sqrt(c*c+b*b);
		double e = d-b*(b/d);
		double ans = acos(e/c);
		ans = ans/3.1415926535*180;
		printf("%.8f\n",ans);
		return 0;
	}else {
		double c = b-(tmp*2/a-b);
		double d = sqrt(a*a+c*c);
		double e = d-c*(c/d);
		double ans = acos(e/a);
		ans = ans/3.1415926535*180;
		printf("%.8f\n",ans);
		return 0;
	}

//	printf("%.4f\n",ans);
}
