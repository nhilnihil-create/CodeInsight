#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

ll ans[100009];
int main()
{

   ll n,k,q;
   cin>>n>>k>>q;
   ll Q = q;
   while(q--)
   {
       ll a;
       cin>>a;
       ans[a]++;
   }


   for(int i=1;i<=n;i++)
   {
       ll temp = Q-ans[i];

       if(k-temp>0)
          cout<<"Yes"<<endl;
       else
          cout<<"No"<<endl;
   }



    return 0;
}
