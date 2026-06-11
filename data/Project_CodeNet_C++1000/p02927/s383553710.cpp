//saikyogakusei1_a.cpp
//Sun Sep 15 07:52:00 2019

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
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int m,d;
	cin >> m >> d;

	int ans = 0;
	for (int i=1;i<=d;i++){
		int x = i%10;
		int y= i/10;
		if (x>=2 && y>=2 && x*y<=m){
			ans++;
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}