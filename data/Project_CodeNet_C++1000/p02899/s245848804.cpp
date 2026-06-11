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
int main ()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int ai;
        scanf("%d",&ai);
        a[ai]=i;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
