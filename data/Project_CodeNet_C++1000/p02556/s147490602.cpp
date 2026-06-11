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
const int maxn=2e5+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

int n;
int a[maxn];
int b[maxn];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int p,q;
        cin>>p>>q;
        a[i]=p+q;
        b[i]=p-q;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    printf("%d\n",max(a[n]-a[1],b[n]-b[1]));
    return 0;
}
