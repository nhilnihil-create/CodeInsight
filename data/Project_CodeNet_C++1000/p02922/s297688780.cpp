#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e5+205;
void solve(){
	int a,b; 
	cin>>a>>b; 
	int st = 1;
	int ans = 0;
	for(int i=1;i<=20;i++){
		if(st>=b)break;
		st--;
		st+=a;
		ans++;
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
