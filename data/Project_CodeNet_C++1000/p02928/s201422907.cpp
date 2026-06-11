#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;ll k;cin>>n>>k;
	int a[n];
	rep(i,n) cin>>a[i];

	ll cnt1=0,cnt2=0;
	for(int i=0;i<n;i++){
		for(int j=(i+1)%n;j!=i;j=(j+1)%n){
			if(a[i]>a[j]){
				if(i<j) cnt1++;
				else cnt2++;
			}
		}
	}
	//cout<<cnt1<<" "<<cnt2<<endl;

	ll ans=((((k*(k+1)/2)%MOD*cnt1)%MOD)+(((k-1)*k/2)%MOD*cnt2)%MOD)%MOD;

	cout<<ans<<"\n";
}