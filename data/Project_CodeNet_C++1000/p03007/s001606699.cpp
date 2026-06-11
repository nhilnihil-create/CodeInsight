#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

vector <ll>a;
vector <ll>pl,mi;
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	ll ans=0;
	ans=a[n-1]-a[0];
	for(ll i=1;i<n-1;i++){
		ans+=abs(a[i]);
	}
	cout <<ans<<endl;
	for(ll i=1;i<n-1;i++){
		if(a[i]>0){
			pl.push_back(a[i]);
		}
		else{
			mi.push_back(a[i]);
		}
	}
	ll sum=a[0];
	while(pl.size()!=0){
		cout << sum <<" ";
		ll now=pl.back();
		pl.pop_back();
		cout << now<<endl;
		sum-=now;
	}
	cout << a[n-1] <<" "<< sum<<endl;
	sum=a[n-1]-sum;
	while(mi.size()!=0){
		ll now=mi.back();
		mi.pop_back();
		cout << sum << " " << now<<endl;
		sum-=now;
	}
	//cout << sum;
	// your code goes here
	return 0;
}