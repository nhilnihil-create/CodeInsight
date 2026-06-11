#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <functional>
#include <vector>
#include <stack>
#include <set>
#include <bitset>
using namespace std;
typedef  long long ll;
const int maxn=1e6+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

int a[maxn];
map<int,int> mp;

bool cmp(int a,int b)
{
    return a>b;
}



int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a+1,a+1+n,cmp);
    ll ans=a[1];
    int ti=1;
    for(int i=2;i<=n;i++)
    {
        ti+=2;
        if(ti<=n-1)
        {
            ans+=2*a[i];
        }
        else
        {
            if(ti==n) ans+=a[i];
            else break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
