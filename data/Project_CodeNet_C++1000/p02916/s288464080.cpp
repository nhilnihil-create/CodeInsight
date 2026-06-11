//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,x,i,satis=0,bo=0;
    cin>>n;
    ll a[n],b[n],c[n]= {0};
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        a[i]--;
    }
    for(i=0; i<n; i++)
        cin>>b[i];
    for(i=0; i<n-1; i++)
        cin>>c[i];
    for(i=0; i<n; i++)
    {
        satis+=b[i];
    }
    for(i=0; i<n; i++)
    {
        if(i>0&&a[i]==a[i-1]+1)
            satis+=c[a[i-1]];
    }
    cout<<satis<<endl;



    return 0;
}



