#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define endl "\n"

const ll limit = 1e6+10;

ll arr[limit];

void sieve(){
	for(ll i = 1; i < limit; i++){
		if(arr[i] > 0){
			for(ll j = i + i; j < limit; j += i){
				arr[j] = 3;	
			}
		}
	}
}

int main()
{
	faster;
	ll n;
	cin >> n;

	vector<ll> a(n);

	for(auto &x: a) 
	{
		cin >> x;
		arr[x]++;
	}
	sieve();
	ll cnt = 0;
	for(ll i = 0; i < n; i++){
		if(arr[a[i]] == 1){
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}