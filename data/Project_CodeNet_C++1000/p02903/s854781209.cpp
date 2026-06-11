#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
using namespace std;
int main()
{
    int n,m,A,B;
    cin>>n>>m>>A>>B;
    if(A*2>m||B*2>n)return puts("-1"),0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(i<=B&&j<=A)putchar('1');
        else if(i>B&&j>A)putchar('1');
        else putchar('0');
        if(j==m)puts("");
    }

    return 0;
}
