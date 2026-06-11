#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

const int MAX_N=50000;
int n,m,c;
int dp[MAX_N+1];

int main(){
	cin >> n >> m;
	for(int i=0;i<=n;i++) dp[i]=i;
	
	for(int i=0;i<m;i++){
		cin >> c;
		for(int j=0;j<=n;j++) if(j-c>=0) dp[j] = min(dp[j], dp[j-c]+1);
	}
	
	cout << dp[n] << endl;
	
	return 0;
}