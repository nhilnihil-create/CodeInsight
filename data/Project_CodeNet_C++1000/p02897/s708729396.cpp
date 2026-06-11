#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);

       int t=1;
       //cin>>t;
       while(t--)
       {
               int n;
               cin>>n;
               if(n==1)
                    cout<<1;
               else if(n%2==0)
               {
                    double ans = 0.5;
                    cout<<fixed<<setprecision(10)<<ans;
               }
               else
               {
                    float ans = 1.0*((n/2 + 1.0)/n);
                    cout<<fixed<<setprecision(10)<<ans;
               }
       }
}
