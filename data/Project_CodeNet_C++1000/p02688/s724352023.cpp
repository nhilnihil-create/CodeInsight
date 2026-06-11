#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	int k;
	cin>>k;
	int m;
	int d;
	for (int i = 0; i<k; i++){
		cin>>m;
		for (int j = 0; j<m; j++){
			cin>>d;
			v[d-1]++;
		}
	}
	int ans = 0;
	for (int i = 0; i<n; i++){
		if (v[i] == 0){
			ans++;
		}
	}
	cout<<ans;	
	return 0;
}