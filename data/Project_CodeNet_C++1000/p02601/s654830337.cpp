//msol2020_b.cpp
//Sun Aug  2 20:38:46 2020

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
	int a,b,c,k;
	cin >> a >> b >> c >> k;

	int count = 0;
	while (a>=b){
		b = b*2;
		count++;
	}
	while (b>=c){
		c = c*2;
		count++;
	}

	if (count <= k){
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}
//	printf("%.4f\n",ans);
}