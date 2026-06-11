#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
int a[100005];
int mt[100005];
int main ()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i%2==0)
            mt[1]-=a[i];
        else
            mt[1]+=a[i];
    }
    for(int i=2;i<=n;i++)
        mt[i]=a[i-1]*2-mt[i-1];
    for(int i=1;i<=n;i++)
        printf("%d ",mt[i]);
    printf("\n");
    return 0;
}
