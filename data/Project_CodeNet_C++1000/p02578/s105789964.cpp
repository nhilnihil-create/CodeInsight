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
using namespace std;
typedef unsigned long long ll;
const int maxn=2e5+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

int a[maxn];

int main()
{
    int n;
    cin>>n;
    ll ans=0;
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(maxx>a[i]) ans+=(maxx-a[i]);
        maxx=max(a[i],maxx);
    }
    printf("%lld\n",ans);
    return 0;
}
