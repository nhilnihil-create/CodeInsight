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
int a[105];
int main() {
    int m,n,sum=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]*m*4>=sum) cnt++;
    }
    if(cnt>=m) printf("Yes\n");
    else printf("No\n");
    return 0;
}
