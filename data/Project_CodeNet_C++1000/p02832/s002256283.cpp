//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll n,ans=0,cnt=1,i;
    cin>>n;
    ll a[n];
    for(i=0; i<n; i++)
        cin>>a[i];
    for(i=0; i<n; i++)
    {
        if(a[i]==cnt)
        {
            cnt++;
        }
        else
        {
            ans++;
        }
    }
    if(ans==n)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;



    return 0;
}



