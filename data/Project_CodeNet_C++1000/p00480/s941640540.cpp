#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long

using namespace std;

int main(void){
	int n,tmp;
	cin >> n;
	
	ll dp[n][21];
	memset(dp, 0, sizeof(dp));
	
	vector<int> v;
	for(int i=0;i<n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	
	dp[0][v[0]] = 1;
	for(int i=0;i<v.size()-2;i++){
		for(int j=0;j<21;j++){
			if(dp[i][j] > 0){
				if(0 <= j+v[i+1] && j+v[i+1] <= 20){
					dp[i+1][j+v[i+1]] += dp[i][j];
				}
				if(0 <= j-v[i+1] && j-v[i+1] <= 20){
					dp[i+1][j-v[i+1]] += dp[i][j];
				}
			}
		}
	}
	cout << dp[v.size()-2][v.back()] << endl;
}