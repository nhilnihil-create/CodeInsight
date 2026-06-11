#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000000000000
#define mod 1000000007

/*

求める数は、    (一つの塊での転倒数)*k + Σ(i:0->n-1){(k*(k-1)/2)*smaller[i]}

Σの項の中の、smaller[i]は,一つの塊(配列a)の中でa[i]より小さい数の個数
			k(k-1)/2*smaller[i]は、上式の第一項以外でa[i]より小さい数の総和
*/

int main(){
	ll n,k;cin>>n>>k;
	vector<ll> a(n),smaller(n,0);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}

	ll ans=0;
	for(ll i=0;i<n-1;i++){
		for(ll j=i+1;j<n;j++){
			if(a[i]>a[j]){ans++;}
		}
	}

	ans=(ans*k)%mod;//一つの塊で転倒数はans個

	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(a[i]>a[j]){smaller[i]++;}//a[i]より小さい数の個数
		}
		ans+=(smaller[i]*((k*(k-1)/2)%mod))%mod;
		ans%=mod;
	}

	cout<<ans<<endl;

	return 0;
}