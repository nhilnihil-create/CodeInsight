#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,k;
	cin >> n >> k;
	
	vector<long long> v(n);
	for(long long &e : v)
		cin >> e;

	long long pre = 0;	
	long long ans = 1;

	for(int i = 0;i < n;++i){
		pre += v[i];
		ans += (k >= pre);		
	}

	cout << ans;

	
}