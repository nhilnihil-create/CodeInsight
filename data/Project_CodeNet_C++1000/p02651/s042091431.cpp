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
	
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i = 0; i<n; i++){
		cin>>a[i];
	}

	string s;
	cin>>s;
	vector<ll> basis;
	int res = 0;

	for(ll i = n-1; i>=0; i--){

		for(auto b : basis){
			a[i] = min(a[i] , a[i] ^ b);
		}
		if(a[i]){
			if(s[i] == '0'){
				basis.push_back(a[i]);
			}
			else{
				res = 1;
			}
		}
	}
	cout<<res<<endl;


}
int main(){
	init();
	ll t = 1;
	cin>>t;
	for(ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}
