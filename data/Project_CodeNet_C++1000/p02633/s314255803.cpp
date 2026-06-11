#include<bits/stdc++.h>
#define ll long long
#define TCI int t;cin>>t;while(t--)
#define cinl for(int i=0;i<n;i++)
#define ln "\n"
#define vpair vector< pair <ll , ll > >
#define fr first 
#define sc second 
#define pb emplace_back
#define vll vector<ll>
using namespace std;

const int N=1e5;

void solve()
{
    ll n;
    cin>>n;
    ll ans=0;
    ll cnt=0;
   	while(1)
   	{
   		ans++;
   		cnt+=n;
   		if(cnt%360==0)
   		break;
   	}
   	cout<<ans<<ln;
    
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
