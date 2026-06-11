#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 1000000007
#define PI 3.14159265358979323846
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;

   // cin>>t;
    while(t--)
    {
       ll n,i;
       cin>>n;
       string s;
       cin>>s;
       i=0;
       ll ans=0;
       while(i<n-2)
       {
           if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
           {
               ++ans;
               i+=3;
           }
           else
            ++i;
       }
       cout<<ans;

    }
}
