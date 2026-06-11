#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int D[10000][2];
	bool ok =0;
	for(int i =0;i<n;i++) {
		for(int j =0;j<2;j++) {
			cin >> D[i][j];
		}
		if(i >= 2 && D[i][0] == D[i][1]) {
			if(D[i-2][0] == D[i-2][1] && D[i-1][0] == D[i-1][1]) ok =1;
		}
	}
	cout << ((ok) ? "Yes" : "No");
	return 0;
}