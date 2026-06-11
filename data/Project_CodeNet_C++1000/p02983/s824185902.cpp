#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

const int mod = 2019;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll l,r,ans=2020;
	cin>>l>>r;
	for(ll i=l;i<r;++i){
		for(ll j=i+1;j<=r;++j){
			ans=min(ans,(i*j)%mod);
			if(ans==0){
				cout<<0<<endl;
				exit(0);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}