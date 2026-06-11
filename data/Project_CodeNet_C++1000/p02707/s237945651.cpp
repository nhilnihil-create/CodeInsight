#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 3e5+5;
vector<int>v[N];
void solve(){
	int n; 
	cin>>n; 
	for(int i=2;i<=n;i++){
		int x; 
		cin>>x; 
		v[x].pb(i);
	}
	for(int i=1;i<=n;i++)cout<<v[i].size()<<endl;
	
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
