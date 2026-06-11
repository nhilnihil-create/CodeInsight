#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
#define inf 0x3f3f3f3f
#define lowbit(x) (x&-x)
typedef long long ll;

const int maxn=1e5+5;
const int mod=1e9+7;

using namespace std;
ll a,b,c,x;

int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    if(c>=b)
        printf("%lld\n",a*(b-1)/b);
    else
        printf("%lld\n",a*c/b);
}
