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
int l[200005],r[200005];
char s[200005];
int main() {
    int n,k,c,t=1,pre=0,now;
    cin>>n>>k>>c;
    scanf("%s",s);
    while(s[pre]=='x') pre++;
    l[t++]=pre;
    while(t<=k)
    {
        now=pre+1;
        while(now-pre<=c||s[now]=='x') now++;
        l[t++]=now;
        pre=now;
    }
    pre=n-1;
    t=k;
    while(s[pre]=='x') pre--;
    r[t--]=pre;
    while(t>=1)
    {
        now=pre-1;
        while(pre-now<=c||s[now]=='x') now--;
        r[t--]=now;
        pre=now;
    }
    for(int i=1;i<=k;i++)
        if(l[i]==r[i])
            printf("%d\n",l[i]+1);
    return 0;
}
