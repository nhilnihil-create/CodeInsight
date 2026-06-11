#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<ctime>
#include<bitset>
//#include<unordered_map>
using namespace std;
#define ll long long
#define dd cout<<endl
const long long int inf = 1e18+7;
const int mod = 1e9+7;

inline ll max(ll a,ll b) { return a>b?a:b; }
inline ll min(ll a,ll b) { return a<b?a:b; }
inline ll abs1(ll a) { return a>0?a:-a; }

//const int maxn=


int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int n;
	cin>>n;
	
	vector<ll>v1,v2;
	v1.resize(n),v2.resize(n);
	
	for(ll i=0,x,y;i<n;i++)
	{
		cin>>x>>y;
		v1[i]=x+y;
		v2[i]=x-y;
	}
	
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	
	cout<<max(v1[n-1]-v1[0],v2[n-1]-v2[0])<<endl;
	
	return 0;
}