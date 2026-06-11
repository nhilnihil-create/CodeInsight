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
const int maxn=1e5+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

int a[maxn];
int num[maxn];
int main()
{
    char s[maxn];
    cin>>s;
    int len=strlen(s);
    int ans=0;
    int tmp=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='S') {ans=max(ans,tmp);tmp=0;continue;}
        tmp++;
    }
    if(tmp>0) ans=max(ans,tmp);
    printf("%d\n",ans);
    return 0;
}
