#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fr first
#define sc second
#define pb push_back
const ll mod = 998244353;
const int N = 1e6+205;
ll a[N];
int n; 
ll f(int x){
	ll ret = 0;
	for(int i=1;i<=n;i++){
		ret+=(a[i]-x)*(a[i]-x);
	}
	return ret;
}
void solve(){
	cin>>n; 
	for(int i=1;i<=n;i++)cin>>a[i];
	int st = 0;
	int en = 1e6;
	while(st<=en){
		int mid1 = st+(en-st)/3;
		int mid2 = en-(en-st)/3;
		if(f(mid1)>f(mid2)){
			st = mid1+1;
		}
		else{
			en = mid2-1;
		}
	}
	cout<<f(st)<<endl;
	
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
