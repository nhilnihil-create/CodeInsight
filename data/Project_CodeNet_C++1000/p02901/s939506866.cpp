#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
int ans[20000],p[1005],can[1005];
int main() {
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        p[i]=a;
        int t;
        for(int j=0;j<b;j++)
        {
            scanf("%d",&t);
            can[i]+=pow(2,t-1);
        }
    }
    for(int i=0;i<pow(2,n);i++) ans[i]=INT_MAX;
    ans[0]=0;
    for(int i=1;i<=m;i++)
        for(int j=0;j<pow(2,n);j++) {
            if (ans[j] == INT_MAX) continue;
            ans[j | can[i]] = min(ans[j | can[i]], ans[j] + p[i]);
        }
    if(ans[int(pow(2,n))-1]==INT_MAX) printf("-1\n");
    else printf("%d\n",ans[int(pow(2,n))-1]);
}
