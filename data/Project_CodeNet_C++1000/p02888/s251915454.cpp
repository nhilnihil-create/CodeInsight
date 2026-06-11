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
int cnt[2005],l[2005];
bool cmp(int a,int b)
{
    return a<b;
}
int main() {
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i];
    sort(l+1,l+n+1,cmp);
    cnt[l[1]+l[2]]++;
    for(int i=3;i<=n;i++)
    {
        for(int j=l[i]+1;j<=2000;j++) ans+=cnt[j];
        for(int j=1;j<i;j++) cnt[l[j]+l[i]]++;
    }
    printf("%d\n",ans);
}
