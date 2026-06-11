#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll mininf = -922337203685477;
const ll nax = 1e5 + 5;

ll gcd(ll a, ll b){
	if(a==0){
		return b;
	}
	return gcd(b%a, a); 
}

ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}

int main(){
	IOS
	ll a, b;
	cin >> a >> b;
	cout << lcm(a, b) << '\n';
}
