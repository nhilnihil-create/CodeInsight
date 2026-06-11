#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define MP make_pair
#define F first
#define S second
#define sz(v) (ll)v.size()
#define inf 1000000000000000000
#define vll vector<ll>
using namespace std;
const int N=500005;

void solve()
{
	ll n,k;
	cin>>n>>k;
	if(k==1)
		cout<<0;
	else
		cout<<n-k;
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
 
    
    return 0;
}