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
int a[200005],b[200005];
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    if(n%2) printf("%d\n",b[n/2+1]-a[n/2+1]+1);
    else printf("%d\n",b[n/2+1]-a[n/2+1]+b[n/2]-a[n/2]+1);
    return 0;
}
