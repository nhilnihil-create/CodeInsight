#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
#define db double
#define pi 3.14159265358979323846
#define pow pw
int pw(int a,int b){
    int ans=1;
    while(b){
    if (b%2) ans*=a;
    a*=a;
    b/=2;
    }
    return(ans);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> sieve(n+1);
    for (int i=2;i<=sqrt(n);i++)
    if (sieve[i]==0) 
    for (int j=i*i;j<=n;j+=i) sieve[j]=i;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int j=i,res=1;
        while(sieve[j])
        {
            int d=sieve[j],c=0;
            while(j%d==0)
            {
                c++;
                j/=d;
            }
            res*=(c+1);
        }
        if (j>1) res*=2;
        ans+=i*res;
    }
    cout<<ans;
    return 0;
}