#include<bits/stdc++.h>
#define LL long long
#define inf 0x3fffffff
using namespace std;
 
int m,d;
 
int main()
{
    cin>>m>>d;
    int ans=0;
    for (int i=1;i<=m;i++)
        for (int j=10;j<=d;j++)
            if ((j%10)*(j/10)==i&&j%10>=2&&j/10>=2) ans++;
    cout<<ans<<endl;
    return 0;
}