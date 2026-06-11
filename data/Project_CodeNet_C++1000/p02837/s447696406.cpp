#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
ll n, a[20], maks=-1;
vector<vector<ll>>b(20), c(20);
	
int main(){
	IOS
	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> a[i];
		for(ll j=0;j<a[i];j++){
			ll nomor, isi;
			cin >> nomor >> isi;
			nomor--;
			b[i].pb(nomor);
			c[i].pb(isi);
		}
	}
	for(ll mask=0;mask<(1<<n);mask++){
		bool ok=1;
		ll ans=0;
		for(ll i=0;i<n;i++){
			if(mask&(1<<i)){
				ans++;
				for(ll j=0;j<a[i];j++){
					if((mask&(1ll<<b[i][j]) && c[i][j])){
						continue;
					}
					else if((!(mask&(1ll<<b[i][j])) && !(c[i][j]))){
						 continue;
					}
					else{
						ok=0;
						break;
					}
				}
			}
		}
		if(ok){
			maks=max(maks, ans);
		}
	}
	cout << maks << '\n';
}
