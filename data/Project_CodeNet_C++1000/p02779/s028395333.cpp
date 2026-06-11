//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;

int main()
{
   ll n,i,j;
    cin>>n;
    ll a[n];
    for( i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    bool ok=1;
    for( i=0;i<n-1;i++)
    {
    if(a[i]==a[i+1]){ok=0;break;}
    }
    if(ok)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}



