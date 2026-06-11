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
const ll nax = 1e5+5;
ll n, a[nax], b[nax];
	
int main(){
	IOS
	cin >>n;
	for(int i=0;i<=n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	ll ans=0;
	for(int i=0;i<n;i++){
		ll depan=a[i+1], belakang=a[i], hiro=b[i];
		b[i]-=min(hiro, belakang);
		ans+=min(hiro, belakang);
		hiro=b[i];
		a[i+1]-=min(a[i+1], hiro);
		ans+=min(depan, hiro);
	}
	cout << ans << '\n';
}
