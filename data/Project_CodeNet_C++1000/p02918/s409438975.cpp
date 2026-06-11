#define George_Plover
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 111000
#define LL long long
#define INF (-1)
using namespace std;
int n,m;
char s[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    int sum=1;
    for(int i=0;s[i];i++)
    {
        if(i&&s[i]!=s[i-1])
        {
            sum++;
        }
    }
    sum=max(1,sum-2*m);
    cout<<n-sum<<endl;
    
    return 0;
}
