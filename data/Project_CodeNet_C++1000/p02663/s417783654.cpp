//nomura2020_a.cpp
//Sun Jul  5 19:33:32 2020

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

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int h1,m1,h2,m2,k;
	cin >> h1 >> m1 >> h2 >> m2 >> k;

	int total = (h2-h1)*60;
	if (m2>=m1){
		total+=m2-m1;
	}else {
		total-=m1-m2;
	}
	cout << max(total - k,0) << endl;
//	printf("%.4f\n",ans);
}