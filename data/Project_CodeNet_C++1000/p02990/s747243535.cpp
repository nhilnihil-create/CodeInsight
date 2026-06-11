#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
#define f first
#define s second
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
const double eps=1e-9;
long long C[2002][2002];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<2001;i++)
        C[i][0]=1;
    for(int i=1;i<2001;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        cout<<(C[k-1][i-1]*C[n-k+1][i])%MOD<<"\n";
    return 0;
}
