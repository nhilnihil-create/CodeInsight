#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define PI 3.141592653589793

using namespace std;
using ll = unsigned long long;

int main() {

	int n, d;
	int cnt = 0;
	cin >> n >> d ;

	vector<vector<int>> x(n, vector<int>(d) );

	rep(i, n) {
		rep(j, d) {
			cin >> x[i][j];
		}
	}

	rep(i,n){
		for(int j=i+1;j<n;j++) {

			ll aa = 0;
			rep(p, d) {
				aa += pow(x[i][p] - x[j][p], 2);
			}
			long double D = sqrt(aa);
			int I = sqrt(aa);
			
			if ((double)D - I ==0 )cnt++;
		}
	}


	std::cout << cnt << endl;

	return 0;
}