#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

// #define DEBUG 100

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7,maxn = 100010;
const double PI = acos(-1);

bool solve (int mat[4][4], int *b, int n){
	vector<int> col(4, 0), lin(4, 0);
	int d1 = 0, d2 = 0;

	for (int i=0; i<n; i++){
		for (int j=0; j<3; j++){
			for (int k=0; k<3;  k++){
				if (mat[j][k] == b[i]){
					lin[j]++;
					col[k]++;
					if (j == k) d1++;
					if (j + k == 2) d2++;
				}
			}
		}
	}
	if (d1 == 3 || d2 == 3) return 1;

	for (int i=0; i<3; i++){
		if (lin[i] == 3 || col[i] == 3) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	int mat[4][4], n, b[20];
	for (int i=0;i<3;i++){
		for (int j=0; j<3; j++){
			cin >> mat[i][j];
		}
	}
	cin >> n;

	for (int i=0; i<n; i++){
		cin >> b[i];
	}

	if (solve(mat, b, n)) cout << "Yes" << endl;
	else cout << "No" << endl;
}	

