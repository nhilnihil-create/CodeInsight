//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll n,i,tmp,ans;
    cin>>n;
    ans=n;
    for(i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            tmp=n/i+i-2;
            ans=min(ans,tmp);

        }
    }
    cout<<ans<<endl;


    return 0;
}



