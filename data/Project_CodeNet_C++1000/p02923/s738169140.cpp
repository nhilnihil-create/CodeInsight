#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 303+5;
void solve(){
	int n; 
	cin>>n;
	int ans = 0;
	int mx = 0;
	int lst = -2e9; 
	for(int i=1;i<=n;i++){
		int x; 
		cin>>x; 
		if(x<=lst)mx++;
		else mx = 0;
		ans = max(ans,mx);
		lst = x;
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
