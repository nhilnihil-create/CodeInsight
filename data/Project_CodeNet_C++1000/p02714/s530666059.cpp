#include<bits/stdc++.h>
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define inf 1000000007
#define mod inf
using namespace std;
template <typename T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <typename T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;

int n;
char c[4005];
ll r,g,b,ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]=='R') r++;
		if(c[i]=='G') g++;
		if(c[i]=='B') b++;
	}
	ans=r*g*b;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(c[i]!=c[j])
			{
				int k=j+j-i;
				if(k>n) continue;
				if(c[i]!=c[k]&&c[j]!=c[k])
					ans--;
			}
	cout<<ans<<endl;
	return 0;
}