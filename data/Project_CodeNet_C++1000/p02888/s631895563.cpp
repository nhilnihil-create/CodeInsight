#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
int tr[2005];
int main ()
{
    int n;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tr[i]);
    }
    sort(tr+1,tr+n+1);
    for(int i=1;i<=n-2;i++)
        for(int j=i+1;j<=n-1;j++)
    {
        int sum=tr[i]+tr[j];
        int l=j+1;
        int r=n;
        if(tr[l]>=sum)
            continue;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(tr[mid]<sum)
                l=mid;
            else
                r=mid-1;
        }
        if(l>j)
            ans+=l-j;
    }
    printf("%d\n",ans);
    return 0;
}
