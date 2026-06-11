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
long long ans[100005],s[100005];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i]);
        if(i%2) ans[1]+=s[i];
        else ans[1]-=s[i];
    }
    ans[1]/=2;
    for(int i=2;i<=n;i++) ans[i]=s[i-1]-ans[i-1];
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]*2);
    printf("\n");
}
