#include<iostream>
#include<algorithm> 
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 2e5+5;
const double pi = acos(-1.0);
const ll mod = 1e9+7; 
map<ll,int>mp;
ll n,k,c,cnt;
char s[N];
ll a[N],b[N];
void init(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main()
{
	init();
	cin>>n>>k>>c>>s+1;
	for(ll i=1;i<=n;i++)
	{
		if(s[i]=='o')
		{
			a[cnt++]=i;
			i+=c;
		}
		if(cnt==k)break;
	}
	for(ll i=n;i>=1;i--)
	{
		if(s[i]=='o')
		{
			b[--cnt]=i;
			i-=c;
		}
		if(!cnt)break;
	}
	for(int i=0;i<k;i++)
	if(a[i]==b[i])cout<<a[i]<<endl;
	return 0;
}