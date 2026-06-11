#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mod 1000000007
#define vll vector<ll>
#define inf 1e9 +7
#define pll pair<ll,ll>
#define ff first 
#define ss second 
#define PI acos(-1)
#define endl '\n'
using namespace std;
int main()
{
    fastio; 
    ll T=1;
    //cin>>T; 
    while(T--)
    {
    	ll n;
    	cin>>n;
    	if(n%1000==0)cout<<"0"<<endl;
    	else
    	cout<<1000-n%1000<<endl;
	}
}

