#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
typedef long long int ll;
int main()
{
    char s[200000];
    scanf("%s",s);
    ll sum=0;
    rep(i,strlen(s))
        sum+=s[i]-'0';
    if(sum%9==0)
        printf("Yes");
    else printf("No");
}