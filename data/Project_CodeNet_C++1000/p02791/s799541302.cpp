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
       int n,m,i;
       cin>>n;
       ll arr[n+1];
       for(i=0;i<n;i++)
        cin>>arr[i];
       ll mn=n+1;
       ll ans=0;
       for(i=0;i<n;i++)
        {
            if(arr[i]<=mn)
            {
                ++ans;
                mn=arr[i];
            }
        }
        cout<<ans;
    }
}
