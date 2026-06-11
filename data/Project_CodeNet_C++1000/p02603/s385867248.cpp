#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define endl "\n"

int main()
{
	faster;
	
	ll n;
	cin >> n;

	vector<ll> a(n);

	ll balance = 1000,stock = 0;

	for(auto &x: a) cin >> x;

	for(ll i = 0; i < n; i++){
		if(i != n-1 && a[i] < a[i+1]){
			ll temp = balance/a[i];
			balance %= a[i];
			stock += temp;
		}
		
		else if(i == n-1 || a[i] > a[i+1]){
			balance += (stock * a[i]);
			stock = 0;
		}
	}
	
	cout << balance << endl;

	return 0;
}