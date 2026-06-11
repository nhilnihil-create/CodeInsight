#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>
#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()
#define mod 1000000007
using namespace std;

int main(){
	int q;
	cin >> q;
	string X[q],Y[q];
	rep(i,0,q){
		cin >> X[i];
		cin >> Y[i];
	}

	rep(i,0,q){
		int m = X[i].length();
		int n = Y[i].length();
		int dp[m+1][n+1] = {};
		int maxl=0;
		rep(j,0,m){
			rep(k,0,n){
				if(X[i][j] == Y[i][k]) dp[j+1][k+1] = dp[j][k]+1;
				else dp[j+1][k+1] = max(dp[j][k+1],dp[j+1][k]);
			}
		}
		cout << dp[m][n] << endl;
	}
	return 0;
}

