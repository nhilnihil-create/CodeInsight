#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,k,a[505];
int tcnt[505];
int main()
{
    scanf("%d%d",&n,&k);
    int sums = 0;
    for(int i=0;i<n;++i){scanf("%d",a+i);sums+=a[i];}
    int sq = ceil(sqrt(sums));
    int ans = 0;

    for(int i=1;i<=sq;++i)
    {
        if(sums%i==0){
            int mod=i,tk=k;
            for(int t=0;t<2;++t)
            {
            for(int j=0;j<n;++j)tcnt[j] = a[j]%mod;
            sort(tcnt,tcnt+n);
            int j=0,je=n-1;

            while(j<je){
                int u=tcnt[j];
                tk-=tcnt[j];
                if(tk<0) break;
                while(u&&je>j){
                    if(u>=mod-tcnt[je]){u-=mod-tcnt[je];--je;}
                    else {tcnt[je]+=u;u=0;}
                }
                ++j;
            }
            if(j>=je) ans = max(ans,mod);
            mod = sums/i;tk=k;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
