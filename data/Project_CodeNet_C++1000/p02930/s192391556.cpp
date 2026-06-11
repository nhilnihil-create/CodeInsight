#include <bits/stdc++.h>
using namespace std;

#define MAXN 505

int g[MAXN][MAXN];

void go(int L, int R, int c) {
	if(L == R) return;
	
	int mid = L + (R-L)/2;
	go(L, mid, c+1);
	go(mid+1, R, c+1);
	for(int i = L; i <= mid; i++) {
		for(int j = mid+1; j <= R; j++) {
			g[i][j] = c;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	go(0, n-1, 1);
	
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			cout << g[i][j] << ' ';	
		}
		cout << '\n';
	}
}
