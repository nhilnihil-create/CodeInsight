#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 9223372036854775807;
const ll mininf = -9223372036854775807;
const ll nax = 0;

ll gcd(ll a, ll b){
	if(a==0) return b;
	return gcd(b%a, a);
}

int main(){
	IOS
	ll k, sums=0;
	cin >> k;
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=k;j++){
			for(ll l=1;l<=k;l++){
				sums+=gcd(i, gcd(j, l));
			}
		}
	}
	cout << sums << '\n';
}