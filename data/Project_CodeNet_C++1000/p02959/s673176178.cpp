#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
const long long int m=pow(10,9)+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ans=0;
    cin>>n;
    int a[n+1],b[n];
    for(int i=0;i<n+1;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
    {
        if(a[i]<b[i])
        {
            ans+=a[i];
            b[i]-=a[i];
            a[i]=0;
            //cout<<a[i]<<" "<<b[i]<<endl;
        }
        else
        {
            ans+=b[i];
            a[i]-=b[i];
            b[i]=0;
            //cout<<a[i]<<" "<<b[i]<<endl;
        }
        if(a[i+1]<b[i])
        {
            ans+=a[i+1];
            b[i]-=a[i+1];
            a[i+1]=0;
            //cout<<a[i]<<" "<<b[i]<<endl;
        }
        else
        {
            ans+=b[i];
            a[i+1]-=b[i];
            b[i]=0;
            //cout<<a[i]<<" "<<b[i]<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}