#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,a[100010],b[100010],i=1,j,saidai=0,m=0,L=0,ans=0;
    cin >> n;
    for(i=0;i<n+1;i++)
    {
        cin >> a[i];
    }
    for(i=0;i<n;i++)
    {
        cin >> b[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]>=b[i])
        {
            ans+=b[i];
            continue;
        }
        if(b[i]-a[i]>=a[i+1])
           {
                ans+=a[i+1];
                ans+=a[i];
                a[i+1]=0;
                a[i]=0;
                continue;
           }
        if(a[i]<=b[i])
        {
            ans+=b[i];
            a[i+1]-=b[i]-a[i];
        }
    }
    cout << ans << endl;
    
    return 0;

}
