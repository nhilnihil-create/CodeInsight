#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e5+6;
void solve(){
	ll n,a,b; 
	cin>>n>>a>>b; 
	ll d = (b-a);
	if(d%2==0){
		cout<<d/2<<endl;
		return ;
	}
	cout<<(b-a)/2+min(a,n-b+1)<<endl;
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
/// n = 12
/// 5 8
/// 6 9
/// 7 10
/// 8 11
/// 9 12
/// 10 12
/// 11 11
/// ans = 7;

/// 3 6
/// 2 5
/// 1 4
/// 1 3
/// 2 2
/// ans = 5

///4+(7-4)/2 = 5
///12-7+1+(7-4)/2 =  7

