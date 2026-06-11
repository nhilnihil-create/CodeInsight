#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
#define ll long long
#define inf 0x3f3f3f3f
#define N 100010
#define int long long
#define mod 1000000007
//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector <int> e[N];
int n,k,ans=1;

void dfs(int x,int fa,int a)
{
    for(int i=0;i<e[x].size()-(int)(x!=1);i++)
    {
        ans=ans*(a-i)%mod;
    }
    vector <int>:: iterator it;
    for(it=e[x].begin();it!=e[x].end();it++)
    {
        if(*it==fa)
            continue;
        dfs(*it,x,k-2);
    }
}

signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=2;i<=n;i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans=k;
    dfs(1,0,k-1);
    printf("%lld\n",ans);
	return 0;
}
