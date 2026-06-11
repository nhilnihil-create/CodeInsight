#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(auto i=0;i<n;i++)
#define s(c) static_cast<int>((c).size())

int main(){
	int n;
	cin >> n;

	int A[n][n]{};
	int v1, v2, deg;
	r(i, n){
		cin >> v1 >> deg;
		v1--;

		r(j, deg){
			cin >> v2;
			v2--;
			A[v1][v2] = 1;
		}
	}

	r(i, n){
		cout << A[i][0];
		for(int j = 1; j < n; j++){
			cout << ' ' << A[i][j];
		}
		cout << endl;
	}
	return 0;
}
