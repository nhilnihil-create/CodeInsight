#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> a(n+1), b(n);
	for(int &e : a) cin >> e;
	for(int &e : b) cin >> e;
	
	long long ans = 0;
	for(int i = 0;i < n;++i){
		for(int j = 0;j <= 1;++j){
			ans += min(a[i+j], b[i]);
			int temp = a[i+j];
			a[i+j] -= min(a[i+j], b[i]);
			b[i] -= min(temp,b[i]);
		}
	}

	cout << ans;
}
