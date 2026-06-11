#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
int main() {
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        sum+=t;
    }
    if(sum<=n) printf("%d\n",n-sum);
    else printf("-1\n");
    return 0;
}
