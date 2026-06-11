#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,k;cin>>n>>k;
    int mod=1e9+7;
    int c[2000][2000];
    for (int i=0;i<2000;i++)
        c[i][0]=c[i][i]=1;
    for (int i=2;i<2000;i++)
        for (int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    for (int i=1;i<=k;i++)
        cout<<(n-k+1<i?0:(ll)c[n-k+1][i])*c[k-1][i-1]%mod<<endl;
    return 0;
}