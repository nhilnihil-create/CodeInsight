#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
#define ll long long
#define inf 0x3f3f3f3f
#define N 200010
#define int long long
//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int a[N],sum[N];

bool cmp(int a,int b)
{
    return a>b;
}

signed main(){
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    ll ans=0;
    n--;
    if(n%2==1)
        ans=2*sum[(n+1)/2]-a[1];
    else
        ans=2*sum[n/2+1]-a[1]-a[n/2+1];
    printf("%lld\n",ans);
	return 0;
}
