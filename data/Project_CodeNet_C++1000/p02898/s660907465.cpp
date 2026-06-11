//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll n,i,x,k,ans=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x>=k) ans++;
    }
    cout<<ans<<endl;

    return 0;
}



