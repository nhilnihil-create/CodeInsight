#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	vector<int> res(n+1);
	for (int i = n; 0 < i; i--){
		int cnt = 0;
		for (int j = 2*i; j <= n; j+=i){
			cnt ^= res[j];
		}
		res[i] = cnt^a[i];
	}	
	vector<int> x;
	for (int i=1; i <= n; i++){
		if (res[i]){
			x.push_back(i);
		}
	}
	cout << x.size() << endl;
	for (int i = 0; i<x.size(); i++){
		cout << x[i] << ' ';
	}
	cout << endl;
}