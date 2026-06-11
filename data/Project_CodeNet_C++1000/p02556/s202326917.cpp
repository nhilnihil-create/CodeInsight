#include<bits/stdc++.h>
using namespace std;
const long long int  modu=1e9+7;
#define endl '\n'
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define inp(x)  for(auto &t:x) cin>>t;
#define itr     vector<int>::iterator
#define debug(a) cout << #a << "=" << a << ' '<<endl;
#define out(x)  for(auto &t:x) cout<<t<<" "; cout<<endl;
#define ff first
#define ss second
#define pb push_back
#define initialize(a,v)  for(int i=0;i<a.size();++i) a[i]=v;
#define all(x) x.begin(),x.end()
#define mpt(mp) for(auto it=mp.begin();it!=mp.end();it++)
#define trav(x) for(int i=0;i<(int)x.size();++i)
#define mkp(a,b) make_pair(a,b)
#define sz(x)  (int)x.size()

int noofdig(int N)
{
	return floor(log10(N))+1;
}
int bits_count(unsigned int u)
{
     unsigned int uCount;

     uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
     return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

ll f(ll a)
{

return 0;

}



void pre()
{

}



void solve()
{
	int n;
	cin>>n;
	
    vector<vector<ll>>f(4,vector<ll>(n));
    
    for(int i=0;i<n;++i)
    {
    	int x,y;
    	cin>>x>>y;
    	f[0][i]= x+y;
    	f[1][i]= x-y;
    	f[2][i]=-x+y;
    	f[3][i]=-x-y;
    }
    
    for(int i=0;i<4;++i)
    {
    	sort(all(f[i]));
    }
    
    ll mx=-1;
    
    for(int i=0;i<4;++i)
    mx=max(mx,abs(f[i][0]-f[i][n-1]));
	
	cout<<mx<<endl;
	






}



int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
