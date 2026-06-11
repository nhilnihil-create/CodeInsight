//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,k,q,x,i,j;
    cin>>n>>k>>q;
    ll a[n],query[n]={0};
    for(i=0; i<q; i++)
    {
        cin>>x;
        query[x-1]++;
    }
    for(i=0; i<n; i++)
    {
        a[i]=k;
    }

    for(i=0; i<n; i++)
    {
        if(a[i]+query[i]-q>0)
           cout<<"Yes"<<endl;
        else
          cout<<"No"<<endl;
       // cout<<a[i]<<" ";

    }



    return 0;
}



