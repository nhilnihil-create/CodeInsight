#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 200005

ll fastpower (ll b , ll p){
    ll k= p%2 ? b : 1 ;
    return p==0 ? 1 : k*(fastpower(b*b,p/2));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ll ans=0;
	if(n==2) ans=a[n-1];
	else{
		ans=a[n-1];
		int i=n-2,k=n-2,x=0;
		while(1){
			ans+=a[i];
			x++;
			k--;
			if(k==0) break;
			if(x==2) i--,x=0;
		}
	}
	cout<<ans;
}