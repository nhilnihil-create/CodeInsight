#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
int main()
{


   ll a,b;

   cin>>a>>b;

   if(b%2!=0)
   {
       cout<<"No"<<endl;
       return 0;
   }

    if((a*2)>b||(a*4)<b)cout<<"No"<<endl;

   else cout<<"Yes"<<endl;

}


