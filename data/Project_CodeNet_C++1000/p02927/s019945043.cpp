#include <bits/stdc++.h>
#define mem(s,t) memset(s,t,sizeof(s))
#define pb(s) push_back(s)
#define inf 0x3f3f3f3f
#define mn 100010
typedef long long ll;
using namespace std;

int main()
{
    int ans=0;
    int m,d,i,j;
    cin>>m>>d;
    for (i=4;i<=m;i++)
    for (j=20;j<=d;j++)
    if (j%10>=2&&((j/10)*(j%10)==i)) ans++;
    cout<<ans<<endl;
    return 0;
}

