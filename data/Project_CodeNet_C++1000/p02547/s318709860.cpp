                           //SILENT KILLER
              //HARD WORK BEATS TALENT WHEN TALENT DOESNOT WORK HARD
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  ll n;
    cin>>n;
    ll a[n+2],b[n+3];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
  ll f=0;
    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]==b[i])cnt++;
        else cnt=0;
        if(cnt==3)
        {
            f=1;
            break;
        }

    }


    if(f==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


}
















