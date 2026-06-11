#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    int ans=0,now=0;
    do
    {
        ans+=x,ans%=360,now++;
    }
    while(ans%360);
    printf("%d",now);
    return 0;
}