#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int g[550][550];
void dfs(int l,int r,int val)
{
    if(l==r) return;
    int mid=(l+r)/2;
    for(int i=l;i<=mid;i++)
    {
        for(int j=mid+1;j<=r;j++)
        {
            g[i][j]=val;
        }
    }
    dfs(l,mid,val+1);dfs(mid+1,r,val+1);
}
int main()
{
	int n;
	scanf("%d",&n);
	dfs(1,n,1);
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            printf("%d",g[i][j]);
            if(j==n) printf("\n");
            else printf(" ");
        }
    }
	return 0;
}
