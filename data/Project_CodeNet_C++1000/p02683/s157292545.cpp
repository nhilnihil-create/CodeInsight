#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int MAXn = 1e7+8;

int main(){
	int n, m ,x;
	cin >> n >> m >> x;
	vector<int> c(n+1);
	vector<int> a[n+1];
	int tmp;
	for(int i = 0; i<n; i++){
		cin >> c[i];
		for(int j = 0; j<m; j++){
			cin >> tmp;
			a[i].push_back(tmp);
		}
	}
	
	int mcost = MAXn;
	for(int i=1; i<(1 << n); i++){
		vector<int> ans(m,0);
		int cost = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				for(int k = 0; k<m; k++){
					ans[k] += a[j][k];
				}
				cost += c[j];
			}
		}
		bool flag = 1;
		for(int j = 0; j<m; j++){
			if(ans[j] < x){
				flag = 0;
				break;
			}
		}
		if(flag){
			mcost = min(mcost, cost);
		}
	}
	if(mcost == MAXn){
		cout << -1;
	}
	else{
		cout << mcost;
	}
	return 0;
} 