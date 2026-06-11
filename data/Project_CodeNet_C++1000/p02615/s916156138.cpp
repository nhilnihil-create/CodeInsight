#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<ll> a = vector<ll>(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	ll sum = a[n-1];
	int idx = n-2;
	bool b = false;
	for(int i = n-2; i > 0; i--){
		sum += a[idx];
		if(b){
			idx--;
		}
		b = !b;
	}
	cout << sum << endl;
	return 0;
}
