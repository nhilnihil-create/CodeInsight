#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1e9+5;
const int N=2e5+5;
const int mod=1e9+7;


		
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> a(n);
	for(ll& x:a) cin>>x;
	a.push_back(-1);
	ll ans=1000;
	ll pre=1e18;
	for(int i=0;i<n;++i){
		if(a[i]<a[i+1]){
			pre=min(pre,a[i]);
		}
		else{
			ll rem=ans%pre;
			ll num=ans/pre;
			ans=rem+num*a[i];
			pre=a[i+1];
		}
	}
	cout<<ans;
	return 0;
}
