#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()
#define mod 1000000007
int main(){
	ll n,k,sum=0;
	cin>>n>>k;
	for(ll i=k;i<=n+1;i++){
		sum=((sum+(i*((n-i+1)%mod))+1)%mod)%mod;
	}
	cout << sum;
	return 0;
}