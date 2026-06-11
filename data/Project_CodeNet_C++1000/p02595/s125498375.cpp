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
typedef long long ll;
const int maxn=3e5+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

struct node
{
    ll x;
    ll y;
    double dis;
}a[maxn];

int main()
{
    int n,d;
    cin>>n>>d;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        a[i].dis=sqrt(a[i].x*a[i].x+a[i].y*a[i].y);
        if(a[i].dis<=d) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
