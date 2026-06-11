#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int m,d;
    scanf("%d%d",&m,&d);

    ll ans=0;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=d;j++)
        {
            int t=j/10;
            int g=j%10;

            if (t>=2 && g>=2 && t*g==i) ans++;
        }
    }

    printf("%lld\n",ans);
}
