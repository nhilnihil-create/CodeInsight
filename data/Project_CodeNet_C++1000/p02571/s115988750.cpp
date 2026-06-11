#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e5+5;
void solve(){
	string s,t; 
	cin>>s>>t; 
	int n = s.size();
	int m = t.size();
	int ans = 1e9;
	for(int i=0;i<=n-m;i++){
		int trt = 0;
		for(int j=0;j<m;j++){
			if(t[j]!=s[i+j])trt++;
		}
		ans = min(ans,trt);
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
