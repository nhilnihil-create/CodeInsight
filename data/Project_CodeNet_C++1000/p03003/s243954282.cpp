#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=2e3+5;
const int mod=1e9+7;
int d[maxm][maxm];
int a[maxm];
int b[maxm];
int n,m;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    //初始化一边为0的情况,因为下面dp的时候不枚举0
    for(int i=0;i<=n;i++)d[i][0]=1;
    for(int i=0;i<=m;i++)d[0][i]=1;
    //dp
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[i][j]=(d[i-1][j]+d[i][j-1]-d[i-1][j-1])%mod;
            if(a[i]==b[j])d[i][j]=(d[i][j]+d[i-1][j-1])%mod;
        }
    }
    cout<<(d[n][m]+mod)%mod<<endl;
    return 0;
}
/*
令d[i][j]表示序列a前i个数,序列b前j个数匹配的子序列数,
转移:
d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]
计算d[i][j]的时候,d[i-1][j]和d[i][j-1]一定已经计算出来了,
方案数为d[i-1][j]加上d[i][j-1],因为d[i-1][j-1]重复计算了,要容斥掉.

如果a[i]==b[j],那么d[i][j]+=d[i-1][j-1]
因为可以将a[i]和b[j]加入d[i-1][j-1]的每个匹配的末尾,方案数为d[i-1][j-1]

*/
