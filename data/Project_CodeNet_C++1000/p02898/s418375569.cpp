#include<bits/stdc++.h>
using namespace std;

int main()
{
   typedef long ll;
   ll n,k;cin>>n>>k;
   ll cnt=0;

   while(n--){
    ll e;
    cin>>e;
    if(k<=e)cnt++;
   }
   cout<<cnt<<endl;
   }


