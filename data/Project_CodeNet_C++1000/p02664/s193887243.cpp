#include<bits/stdc++.h>
using namespace std;
#define ff          first
#define ss          second
#define ll         	long long int
#define pb          push_back
#define ar 			array
#define mp 			make_pair
#define f(i,n)   	for(ll i =0;i<n;i++)
#define inf 		INT_MAX
#define pll 		pair<ll, pair<ll,ll>>
const ll INF = 1e18;
void init(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
}
void solve(){
	
	
	
	string s;
	cin>>s;
	for(int i = 0;i<s.length() ;i++){
		if(s[i] == '?'){
			s[i] = 'D';
		}
	}
	cout<<s<<endl;

}
int main(){
	init();
	ll t = 1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}
