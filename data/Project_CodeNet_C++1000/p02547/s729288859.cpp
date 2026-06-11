#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n,m,j,y,i,k,x,d,c=0,z,p,q;
    cin>>n;
    ll a[n+1],b[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    ll mx=-1;
    for(i=0;i<n;i++)
    {
        if(a[i]==b[i])c++;
        else
        {
            mx=max(c,mx);
            c=0;
        }
    }
    if(max(mx,c)>=3)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;



}
int main()
{
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
