#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll x;
	cin >> x;
	for(ll i=-203; i<=203; i++){
		for(ll j=-203; j<=203; j++){
			if(i*i*i*i*i - j*j*j*j*j == x){
				cout << i << " " << j;
				return 0;
			}
		}
	}
}