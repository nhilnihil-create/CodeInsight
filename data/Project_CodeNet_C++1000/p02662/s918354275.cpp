#include <bits/stdc++.h>
using namespace std;


int main() {
	int s;
	int i;
	int j;
  	int k;
	int n;
	int a[3010];
	int np[3010][3010];

	cin >> n >> s;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < s+1; j++) {
			np[i][j]=0;
		}
	}
	np[0][0]=2;
	np[0][a[0]]=1;
  	for (i = 1; i < n; i++) {
		for (j = 0; j <= s; j++) {
			np[i][j]=2*np[i-1][j];
			np[i][j]=np[i][j] % 998244353;
		}
		for (j = 0; j <= s-a[i]; j++) {
			k=j+a[i];
			np[i][k]=np[i][k]+np[i-1][j];
			np[i][k]=np[i][k] % 998244353;
		}
    }
	cout << np[n-1][s];
	return 0;
}