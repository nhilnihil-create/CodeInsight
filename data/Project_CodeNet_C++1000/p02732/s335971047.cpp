#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll n;


int main(){
	cin >> n;
	
	map<int,ll> m;
	vector<ll> a(n);
	for ( int i = 0; i < n; i++ ){
		cin >> a[i];
		m[a[i]]++;
	}
	
	ll count = 0;
	for ( auto it : m ){
		count += it.second * (it.second-1) / 2;
	}
	
	for ( int i = 0; i < n; i++ ){
		cout << count - (m[a[i]]-1) << endl;
	}
	
	return 0;
}

