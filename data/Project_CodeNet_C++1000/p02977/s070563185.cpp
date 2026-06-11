#include<cstdio>
#include<vector>
#include<cstdlib>
#include<map>
#define RI register int
#define CI const int&
using namespace std;
const int N=100005;
int n,cur,pfx[N<<1]; vector <int> v[N<<1]; map <int,int> Hash;
inline void addedge(CI x,CI y)
{
	printf("%d %d\n",x,y); v[x].push_back(y); v[y].push_back(x);
}
inline void DFS(CI now=1,CI fa=0)
{
	pfx[now]=pfx[fa]^(now<=n?now:now-n);
	if (pfx[now]==n) addedge(1,n),addedge(now,n<<1),exit(0);
	if (Hash.count(pfx[now]^n^1))
	addedge(Hash[pfx[now]^n^1],n),addedge(now,n<<1),exit(0);
	Hash[pfx[now]]=now; for (vector <int>::iterator it=v[now].begin();it!=v[now].end();++it)
	if (*it!=fa) DFS(*it,now);
}
int main()
{
	//freopen("CODE.in","r",stdin); freopen("CODE.out","w",stdout);
	scanf("%d",&n); for (cur=1;cur<n;cur<<=1);
	if (cur==n) return puts("No"),0; puts("Yes");
	addedge(1,2); addedge(2,3); addedge(3,n+1); addedge(n+1,n+2); addedge(n+2,n+3);
	for (RI i=5;i<=n;i+=2) addedge(1,i-1),addedge(i,i-1),addedge(1,n+i),addedge(n+i,n+i-1);
	if (n&1) return 0; return DFS(),0;
}