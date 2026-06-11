#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll mininf = -922337203685477;
const ll nax = 0;

ll a, b;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b;
	for(ll i = 1; i <= 100000	; i++){
		ll temp = i * 8ll / 100ll;
		ll temp2 = i * 10ll / 100ll;
		if(temp == a && temp2 == b){
			 cout << i << '\n';
			 return 0;
		 }
	 }
	 cout << -1 << '\n';
}
