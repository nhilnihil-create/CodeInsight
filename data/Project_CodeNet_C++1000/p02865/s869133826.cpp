//programking2_a.cpp
//Sun Dec  1 10:34:25 2019

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
	int n;
	cin >> n;

	int ans = 0;
	for (int i=1;i<n;i++){
		if (n-i <= i){
			break;
		}
		ans++;
	}


	cout << ans << endl;
//	printf("%.4f\n",ans);
}