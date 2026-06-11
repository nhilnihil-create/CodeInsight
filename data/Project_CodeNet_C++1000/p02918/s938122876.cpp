#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,k;
char s[100005];

int main()
{
    scanf("%d%d\n",&n,&k);
    scanf("%s",s);
    int hp=0,np=0;
    for(int i=0;i<n;++i){
        if(i==0||s[i-1]!=s[i])++np;
        else ++hp;
    }
    np-=1;
    hp += min(np,2*k);
    printf("%d\n",hp);
    return 0;
}
