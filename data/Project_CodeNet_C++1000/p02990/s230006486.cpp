#include<bits/stdc++.h>
#define LL long long
#define Max 2005
const LL mod=1e9+7;
const LL LL_MAX=9223372036854775807;
using namespace std;
LL C[Max][Max];
void Compare_C () {// play table
    C[0][0]=1;
    for(int i=1;i<Max;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
int main()
{
    Compare_C();
    int b,r,c;
    scanf("%d%d",&c,&b);
    r=c-b+1;
    for(int i=1;i<=b;i++){
        printf("%lld\n",(C[b-1][i-1]*C[r][i])%mod);
    }
    return 0;
}

