#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	ll a[200010],b[200010];
	for(ll i=0;i<n;i++){
		cin>>a[i];
		a[i]-=1;
	}
	b[0]=0;
	for(ll i=1;i<=n;i++){
		b[i]=b[i-1]+a[i-1];
		b[i]%=k;
   // 	cout <<b[i];
	}
//	cout <<endl;
	map<ll,ll>ch;
	ll ans=0;
	for(ll i=0;i<=n;i++){
		if(i-k>=0){
		ll mae=b[i-k];
		ch[mae]--;
		}		
		ll now=b[i];
		ans+=ch[now];
		ch[now]++;
	}
	cout <<ans;
	// your code goes here
	return 0;
}