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



int main()
{
    char tmp;
    int ans=0;
    while(scanf("%c",&tmp)!=EOF&&tmp!='\n')
    {
        ans=(ans+tmp-'0')%9;
    }
    if(ans==0) printf("Yes\n");
    else printf("No\n");
    return 0;
}
