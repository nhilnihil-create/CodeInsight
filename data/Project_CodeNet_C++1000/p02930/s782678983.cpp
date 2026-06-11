#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD (LL)(1e9+7)

int A[500][500];

void solve(int l, int r, int s){
	if(r-l == 2){
		A[l][l+1] = s;
		A[l+1][l] = s;
		return;
	}
	if(r-l < 2) return;
	solve(l, (l+r)/2, s+1);
	solve((l+r)/2, r, s+1);
	for(int i=l; i<(l+r)/2; i++){
		for(int j=(l+r)/2; j<r; j++){
			A[i][j] = s;
			A[j][i] = s;
		}
	}
}

int main(){
	int N;
	cin >> N;
	solve(0, N, 1);
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if(j != i+1) cout << " ";
			cout << A[i][j];
		}
		cout << endl;
	}
}