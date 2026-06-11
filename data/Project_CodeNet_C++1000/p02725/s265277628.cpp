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
int a[200005];
int main() {
    int k,n,ans=0;
    cin>>k>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) ans=max(ans,a[i+1]-a[i]);
    ans=max(ans,k-a[n]+a[1]);
    printf("%d\n",k-ans);
    return 0;
}
