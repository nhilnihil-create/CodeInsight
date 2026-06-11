#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j=0,c,n,m,a[100000],dp[100000],MOD=1000000007,b=0;
    dp[1]=1;
    dp[2]=2;
    cin >> n >> m;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]==1)
        {
            dp[1]=0;
            dp[2]=1;
            j=1;
            b++;
        }
        if(a[i]==2)
        {
            dp[2]=0;
            dp[1]=1;
            j=1;
            b++;
        }
    }
    if(b==2)
    {
        cout << '0' << endl;
        return 0;
    }
    a[m]=0;
    for(i=3;i<=n;i++)
    {
        if(a[j]==i)
        {
            dp[i]=0;
            j++;
        }
        else
        {
          dp[i]=(dp[i-1]+dp[i-2])%MOD;  
        }
    }
    cout << dp[n] << endl;
    return 0;

}
