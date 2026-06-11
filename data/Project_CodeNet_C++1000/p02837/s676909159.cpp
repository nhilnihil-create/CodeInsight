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
ll n, maks=-1, arr[20];
vector<ll>b[20], c[20];
	
int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		for(int j=0;j<arr[i];j++){
			ll satu, dua;
			cin >> satu >> dua;
			satu--;
			b[i].pb(satu), c[i].pb(dua);
		}
	}
	for(int mask=0;mask<(1<<n);mask++){
		ll ans=0;
		bool cek=1;
		for(int i=0;i<n;i++){
			if((mask>>i)&1){
				ans++;
				for(int j=0;j<arr[i];j++){
					if((1&(mask>>b[i][j]) && c[i][j])){
						continue;
					}
					else if((!(1&(mask>>b[i][j])) && !c[i][j])){
						continue;
					}
					else{
						cek=0;
						break;
					}
				}
			}
		}
		if(cek){
			maks=max(maks, ans);
		}
	}
	cout << maks << '\n';
}
