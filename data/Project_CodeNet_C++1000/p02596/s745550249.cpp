#include <bits/stdc++.h>

using namespace std;
int k,ans,now;
int main()
{
    scanf("%d",&k);
    while(ans<=80000000){
        ans++;
        now=(now*10+7)%k;
        if(now==0){printf("%d",ans);
        return 0;
        }
    }
    printf("-1");
    return 0;
}