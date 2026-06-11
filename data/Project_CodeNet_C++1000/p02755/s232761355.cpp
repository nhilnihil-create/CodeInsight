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
ll a, b;

int main(){
	IOS
	cin >> a >> b;
	ll ans1=ceil((double)(a*100)/8);
	ll ans2=ceil((double)(b*100)/10);
	//cout << ans1 << " " << ans2 << endl;
	bool kesatu=false, kedua=false;
	if((ans2*8)/100==a&&(ans2*10)/100==b){
		kesatu=true;
	}
	if((ans1*8)/100==a&&(ans1*10)/100==b){
		kedua=true;
	}
	if(kesatu&&kedua){
		cout << min(ans1, ans2) << '\n';
	}
	else if(kesatu){
		cout << ans2 << '\n';
 	}
 	else if(kedua){
 		cout << ans1 << '\n';
 	}
 	else{
 		cout << -1 << '\n';
 	}
}