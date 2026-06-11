#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;

/// Info.
///****************************************************************************************************************************************///
/// author                : BAHAA El-DEEN OSAMA .
/// Problem name          : I - Tsundoku
/// Method                : brute force
/// Online judge          : vjudge(Contest)
/// Date                  : 8/6/2020
///****************************************************************************************************************************************///
#define ll   long long


int main()
{

    ll m,n,k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	vector<ll> b(m);
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	for(int i = 0; i<m; i++){
		cin >> b[i];
	}
	vector<ll> sumA(n+1);
	vector<ll> sumB(m+1);
	for(int i = 0; i<n; i++){
		sumA[i+1] = sumA[i] + a[i];
	}
	for(int i = 0; i<m; i++){
		sumB[i+1] = sumB[i] + b[i];
	}
	int total = 0;
	for(int i = 0; i<= n;i++){
		ll other = k-sumA[i];
		if(other < 0){
			continue;
		}
		int l = lower_bound(sumB.begin(), sumB.end(), other)-sumB.begin();
		if(l>m||sumB[l]>other){
			--l;
		}
		total = max(total, i+l);
	}
	cout << total;

 return 0;
}
