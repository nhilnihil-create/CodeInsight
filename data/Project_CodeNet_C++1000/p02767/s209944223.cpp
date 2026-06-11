#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int i,n,k,t1;
    double sum=0,t;
    ll ans=0;
    cin>>n;
    int x[n+1];
    for(i=0;i<n;i++)
    {
        cin>>x[i];
        sum=sum+x[i];
    }
    t=sum/n;
    //cout<<t<<endl;
    k=(int)(t*10.0);
    //cout<<k<<endl;
   // cout<<k%10<<endl;
   // cout<<ceil(t)<<endl;
    if(k%10>5)
        t1=(k/10)+1;
    else
        t1=(k/10);
   // cout<<t1<<endl;
    for(i=0;i<n;i++)
    {
        ans=ans+((t1-x[i])*(t1-x[i]));
    }
    cout<<ans<<endl;
    return 0;
    }
