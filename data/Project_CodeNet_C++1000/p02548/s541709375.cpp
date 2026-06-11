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
    //cin>>t;
    //int c=0;
    while(t--) {

       ll n,i,j,k,ans=0;
       cin>>n;
       for(i=1;i<=n;i++)
       {
           j=n/i;
           if(n%i==0)
            --j;
           ans+=j;
       }
       cout<<ans;
    }

}
