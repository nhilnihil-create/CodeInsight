#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
using namespace std;

const int maxs = 2e5+9;
int a[maxs];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    while(k--)
    {
        int b[maxs];
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
        {
            int l = max(1,i-a[i]);
            int r = min(n,i+a[i]);

            b[l]++;
            b[r+1]--;
        }

        int flag = 1;
        for(int i=1;i<=n;i++)
        {
            a[i] = a[i-1] + b[i];
            if(a[i]!=n) flag = 0;
        }
        if(flag) break;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
