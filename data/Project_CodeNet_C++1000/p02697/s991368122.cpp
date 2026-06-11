//abc165_e.cpp
//Mon May 25 21:36:24 2020

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
	int n,m;
	cin >> n >> m;

	int low = 1;
	int high = n;
	// int check = 0;
	// if (n%2==0){
		// check = n/2;
	// }
	for (int i=0;i<m;i++){
		if (n%2==1){
			cout << low << " " << high << endl;
		}else {
			// int x = 0;
			if (n/2==high-low || n/2-1==high-low){
				high--;
			}
			cout << low << " " << high << endl;
		}
		low++;
		high--;
	}

//	printf("%.4f\n",ans);
}