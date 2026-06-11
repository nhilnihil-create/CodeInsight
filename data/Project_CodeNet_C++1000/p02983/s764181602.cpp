#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
ll l, r, mins=inf;
	
int main(){
	IOS
	cin >> l >> r;
	if(r-l>=2019){
		cout << 0 << '\n';
		return 0;
	}
	for(ll i=l;i<r;i++){
		for(ll j=i+1;j<=r;j++){
			mins=min(mins, (i*j)%2019);
		}
	}
	cout << mins << '\n';
}
