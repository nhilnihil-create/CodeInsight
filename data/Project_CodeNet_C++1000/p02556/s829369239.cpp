#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N][2];
int n;
ll GetManhattan(int n, int dem)
{
    ll ans=0,Min,Max;
    int i,j,k;
    for(i=0;i<(1<<(dem));i++) {
        Min=1e18,Max=-1e17;
        for(j=0;j<n;j++){
            ll sum = 0;
            for(k=0;k<2;k++){
                if(i&(1<<k)) sum+=a[j][k];
                else sum-=a[j][k];
            }
            if(sum>Max) Max=sum;
            if(sum<Min) Min=sum;
        }
        ans=max(ans,Max-Min);
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
            scanf("%lld",&a[i][j]);
    ll ans=GetManhattan(n,2);
    printf("%lld\n", ans);
    return 0;
}
