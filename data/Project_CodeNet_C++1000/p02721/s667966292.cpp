#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MP make_pair
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PLI pair<ll, int>
#define PIL pair<int, ll>
#define STR string
#define Fst first
#define Snd second
#define SHN 1e9
#define LSHN 1e18
using namespace std;
int n,m,k;
string s;
int mx[800010];
vector<int> v[200010];
int l[200010],r[200010];
int siz=1;
int search(int x,int y)
{
	if (x>y) return 0;
	x+=siz/2,y+=siz/2+1;
	int res=0;
	while (x<y)
	{
		if (x%2) res=max(res,mx[x++]); 
		if (y%2) res=max(res,mx[--y]); 
		x/=2,y/=2;
	} 
	return res;
}
void update(int x,int y)
{
	x+=siz/2;
	while (x) mx[x]=max(mx[x],y),x/=2;
}
int main()
{
	cin >>n>>m>>k>>s;
	while (siz<2*(n+2)) siz*=2;
	for (int i=0;i<n;i++)
	{
		l[i]=search(0,i-k-1)+(s[i]=='o');
		update(i,l[i]);
	}
	memset(mx,0,sizeof(mx));
	for (int i=n-1;i>=0;i--)
	{
		r[i]=search(i+k+1,n-1)+(s[i]=='o');
		update(i,r[i]);
	}
	for (int i=1;i<n;i++) l[i]=max(l[i],l[i-1]); 
	for (int i=n-2;i>=0;i--) r[i]=max(r[i],r[i+1]); 
	for (int i=0;i<n;i++)
	{
		int li=(i-k-1<0 ? 0 : l[i-k-1]);
		int ri=(i+k+1>=n ? 0 : r[i+k+1]);
		//cout <<i<<" "<<li<<" "<<ri<<" ##\n";
		if (s[i]=='o' && li+ri==m-1) v[li].push_back(i+1);
	}
	for (int i=0;i<=m;i++)
	{
		//cout <<i<<" "<<v[i].size()<<" ##\n"; 
		if (v[i].size()==1) cout <<v[i][0]<<"\n";
	}
	return 0; 
}