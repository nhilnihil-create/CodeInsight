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
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
using namespace std;
int ans[2020];
int n,x,y;
int main()
{
    cin>>n>>x>>y;
    for(int  i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            ans[min(i-j,abs(x-j)+abs(y-i)+1)]++;
        }
    }
    for(int i=1;i<=n-1;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
