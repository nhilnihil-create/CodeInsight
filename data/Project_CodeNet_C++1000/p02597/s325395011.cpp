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

char s[maxn];

int main()
{
    int k;
    cin>>k;
    cin>>s;
    int tot=0;
    for(int i=0;i<k;i++)
    {
        if(s[i]=='R') tot++;
    }
    int ans=0;
    for(int i=0;i<tot;i++)
    {
        if(s[i]=='R') ans++;
    }
    printf("%d\n",tot-ans);
}
