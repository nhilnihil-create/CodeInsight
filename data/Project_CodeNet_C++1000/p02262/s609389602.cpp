#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<iomanip>
#include<complex>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<map>
#include<set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;
typedef pair<int,int> PII;
typedef long long LL;

#define d(x)  cout<<#x<<" = "<<(x)<<endl;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define EP empty()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define REACH(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c,n) sort(c,c+n)
#define VSORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define DFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define DREP(i,n) DFOR(i,n,0)
#define INF 1000000000
#define PI  acos(-1.0)
//cin.tie(0);ios::sync_with_stdio(false);
////////////////////////////////////////////////
long long cnt;
int l,n;
int a[1000000];
VI G;
void insS(int a[],int n,int g)
{
	for(int i=g;i<n;i++)
	{
		int v=a[i];
		int j=i-g;
		while(j>=0&&a[j]>v)
		{
			a[j+g]=a[j];
			j-=g;
			cnt++;
		}
		a[j+g]=v;
	}
}

void shellS(int a[],int n)
{
	for(int h=1;;)
	{
		if(h>n)break;
		G.PB(h);
		h=h*3+1;
	}
	
	for(int i=G.size()-1;i>=0;i--)
	{
		insS(a,n,G[i]);
	}
}

int main()
{
	cin>>n;
	REP(i,n)
	{
		scanf("%d",a+i);
	}
	cnt=0;
	shellS(a,n);
	cout<<G.size()<<endl;
	DREP(i,SZ(G))
	{
		printf("%d",G[i]);
		if(i)printf(" ");
	}
	printf("\n");
	printf("%d\n",cnt);
	REP(i,n)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
	