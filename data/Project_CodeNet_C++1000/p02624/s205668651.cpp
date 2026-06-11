#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e7+6;
ll a[N];
void solve(){
	for(int i=1;i<N;i++){
		for(int j=i;j<N;j+=i){
			a[j]++;
		}
	}
	ll ans = 0;
	int n; 
	cin>>n; 
	for(ll i=1;i<=n;i++){
		ans+=a[i]*i;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
