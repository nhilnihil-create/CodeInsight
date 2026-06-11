#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

static const int max_n = 1000;
string s1, s2;
int q, c[max_n + 1][max_n + 1];

int lcs(string X, string Y){
	int m = X.size();
	int n = Y.size();
	int maxl = 0;
	X = ' ' + X;
	Y = ' ' + Y;
	for(int i = 0; i <= m; i++){
		c[i][0] = 0;
	}
	for(int j = 1; j <= n; j++){
		c[0][j] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(X[i] == Y[j]){
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if(c[i - 1][j] >= c[i][j - 1]){
				c[i][j] = c[i - 1][j];
			}
			else{
				c[i][j] = c[i][j - 1];
			}
			maxl = max(maxl, c[i][j]);
		}
	}
	return maxl;
}

int main(void){
	cin >> q;
	for( int i = 1; i <= q; i++ ){
		cin >> s1 >> s2;
		cout << lcs(s1, s2) << endl;
	}
	return 0;
}