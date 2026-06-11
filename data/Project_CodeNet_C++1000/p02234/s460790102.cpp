#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <cassert>
typedef unsigned long long ull;
typedef unsigned long ul;
#define rep(i,n) for(unsigned long long i = 0;i<n;i++)
#define clear(c) memset(c,0,sizeof(c))
#define clearm(c) memset(c,-1,sizeof(c))
using namespace std;

int main(){
	int n;

	cin >> n;
	ull dp[100+1][100+1];
	clearm(dp);
	ull r[n],c[n];
	rep(i,n){
		int rr,cc;
		cin >> rr >> cc;
		r[i] = rr;
		c[i] = cc;
	}
	rep(i,n-1){
		dp[i][i+1] = r[i] * c[i+1] * r[i+1];
	}
	rep(i,n){
		dp[i][i] = 0;
	}
	for(int dif = 2;dif<n;dif++){
		for(int i = 0;i + dif<n;i++){
			for(int j = i + 1;j <= i +dif - 1;j++){
				dp[i][i+dif] = min(dp[i][i+dif],dp[i][j] + dp[j+1][i+dif] + r[i] * c[j] * c[i+dif]);
			}
		}
	}
	cout << dp[0][n-1] << endl;
	return 0;
}