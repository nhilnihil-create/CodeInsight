//tokyokaijyo2020_c.cpp
//Sat Jun 27 18:40:37 2020

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
	int n,k;
	cin >> n >> k;

	int a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}

	int imos[n+1];
	for (int i=0;i<k;i++){
		fill(imos,imos+n+1,0);
		for (int j=0;j<n;j++){
			imos[max(j-a[j],0)]++;
			imos[min(j+a[j]+1,n)]--;
		}
		a[0] = imos[0];
		int flag = 1;
		for (int j=1;j<n;j++){
			imos[j] = imos[j-1]+imos[j];
			a[j] = imos[j];
			if (a[j]!=n){
				flag = 0;
			}
		}
		if (flag){
			for (int j=0;j<n;j++){
				cout << n << " ";
			}
			printf("\n");
			return 0;
		}
	}

	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	printf("\n");

}