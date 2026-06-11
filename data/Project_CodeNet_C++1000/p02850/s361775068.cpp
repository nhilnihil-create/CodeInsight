#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;

vector<int> G[100010];
int n;

int color[100010];
map<P,int> ma;

bool visit[100010];
void dfs(int v,int cl)
{
	visit[v]=true;
	int imacl=0;
	for(int i=0;i<G[v].size();i++)
	{
		int w=G[v][i];
		if(visit[w])continue;
		if(imacl==cl)imacl++;
		color[ma[P(v,w)]]=imacl;
		dfs(w,imacl); 
		imacl++;
	}
}
int main(){
	cin>>n;
	fill(visit,visit+n,false);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;a--;b--;
		ma[P(a,b)]=i;
		ma[P(b,a)]=i;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0,100100100);
	int MAX=0;
	for(int i=0;i<n-1;i++)MAX=max(MAX,color[i]);
	
	cout<<MAX+1<<"\n";
	for(int i=0;i<n-1;i++)cout<<color[i]+1<<"\n";
	return 0;
}