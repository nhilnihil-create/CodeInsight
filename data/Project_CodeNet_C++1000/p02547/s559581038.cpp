#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t=1,i,j,k=0,q,p,x,y,n,a,b,d;
    //cin>>t;
    while(t--)
    {
       cin>>n;
       vector<ll>v[n+5];
       for(i=0;i<n;i++)
       {
           cin>>x>>y;
           v[i].push_back(x);
           v[i].push_back(y);
       }
       ll f=0;
       for(i=0;i+2<n;i++)
       {
           for(j=i;j+2<n;j++)
           {
               if(v[j][0]==v[j][1]&&v[j+1][0]==v[j+1][1]&&v[j+2][0]==v[j+2][1])
               {
                   f=1;
                   break;
               }
           }
       }
       if(f==1)
       {
           cout<<"Yes"<<endl;
       }
       else
        cout<<"No"<<endl;
    }

    return 0;
}
