#include<iostream>
#include<algorithm> 
#include<cstdio>
#include<cctype>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 2e5+5;
const double pi = acos(-1.0);
const ll mod = 1e9+7;
void init(){
	ios::sync_with_stdio(false);cin.tie(0);
} 
template<class T>inline void read(T &res)
{
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
vector<ll>a,b;
int main()
{
	init();
	ll n;int ans=0;
	cin>>n;
	for(ll i=2;i*i<=n;i++)
	if(n%i==0)
	{
		a.push_back(i);
		if(i*i!=n)a.push_back(n/i);
	}
	a.push_back(n);
	for(ll i=2;i*i<=n-1;i++)
	if((n-1)%i==0)
	{
		a.push_back(i);
		if(i*i!=n-1)a.push_back((n-1)/i);
	}
	b.push_back(n-1);
	for(int i=0;i<b.size();i++)
	if(n%b[i])ans++;
	for(int i=0;i<a.size();i++)
	{
		ll tmp=n;
		while(tmp%a[i]==0)tmp/=a[i];
		if(tmp%a[i]==1)ans++;
	}
	cout<<ans;
	return 0;
}