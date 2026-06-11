#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e6+5;
string s[66];
int a[66];
void solve(){
	int n; 
	cin>>n; 
	for(int i=1;i<=n;i++)cin>>s[i]>>a[i];
	int ans = 0;
	string tar; 
	cin>>tar; 
	bool can = false;
	for(int i=1;i<=n;i++){
		if(can)ans+=a[i];
		if(s[i]==tar)can = true;
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
