#include<bits/stdc++.h>
// __builtin_ctz : no of trailing zeros
#define int long long
#define ll long long
#define pp pair<int,int>
#define mod 1000000007
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define sa(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define scan() int n; cin>>n ; int a[n]; for(int i = 0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) cout<<a[i]<<' '
using namespace std;
int max(int x, int y)
{
    return x>y ? x : y;
}
int min(int x, int y)
{
    return x<y ? x : y;
}
void _(int&a , int b)
{
    a=(a%mod+b%mod)%mod;
    a=(a+mod)%mod;
}
ll cl(ll a,ll b)
{
    return (a/b)+(!(!(a%b)));
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;cin >> n >> m;vector<pp> v(n);
    for (int i = 0; i < n; ++i)
    {
    	cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(),v.end(),[&](pp p1,pp p2)
    	{
    		return p1.first>p2.first;
    	});
    set<ll> s;
    for(int i=1;i<=m;i++)s.insert(i);int ans=0;
    for (int i = 0; i < v.size(); ++i)
    {
    	int d=m-v[i].second+1;
    	auto it=s.upper_bound(d);
    	if(it!=s.begin())
    	{
    		ans+=v[i].first;
    		it--;
    		s.erase(it);
    	}
    }
    cout << ans;
    }