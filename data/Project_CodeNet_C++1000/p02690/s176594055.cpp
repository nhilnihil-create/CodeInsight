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
ll x;

ll pangkat(ll a, ll b){
	ll curr=1;
	while(b){
		if(b&1){
			curr*=a;
		}
		a*=a;
		b/=2;
	}
	return curr;
}

int main(){
	IOS
	cin >> x;
	for(int i=-2000;i<=2000;i++){
		for(int j=-2000;j<=2000;j++){
			if(pangkat(i, 5)-pangkat(j, 5)==x){
				cout << i << ' ' << j << '\n'; return 0;
			}
		}
	}
}