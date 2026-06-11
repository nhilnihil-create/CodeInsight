#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
	int n, k; cin >> n >> k;
	vector<int> a(n), b(n, 0);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < min(k, 100); i++){
		for(int j = 0; j < n; j++) b[j] = 0;
		for(int j = 0; j < n; j++){
			int left = max(0, j - a[j]);
			b[left]++; 
			int right = a[j] + j;
			if(right < n - 1) b[right + 1]--;
		}
		for(int j= 1; j < n; j++){
			b[j] += b[j - 1];
		}
		a  = b;
	}
	for(int i = 0; i < n; i++){
		cout << b[i] << " ";
	}
	cout << endl;
}