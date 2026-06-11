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
int a[200010],d[400010];
int main()
{
	cin >>n>>m>>k>>s;
	memset(a,-1,sizeof(a));
	int t=0;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='x') continue;
		a[i]=t++,i+=k;
	} 
	for (int i=n-1;i>=0;i--)
		d[i]=max(d[i+1],d[i+k+1]+(s[i]=='o'));
	for (int i=0;i<n;i++)
	{
		if (s[i]=='x') continue;
		if (a[i]!=-1 && d[i+1]+a[i]<m) cout <<i+1<<"\n";
	}
	return 0;
} 