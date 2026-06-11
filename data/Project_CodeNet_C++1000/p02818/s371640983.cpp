#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
///                    BISMILLAHIR RAHMANIR RAHIM

int main()
{
  ll a,b,k,s,l;
   cin>>a>>b>>k;
   if(k<=a)
   {
       cout<<a-k<<" "<<b<<endl;
   }
   else
   {
       if((k-a)<=b)
       {
           cout<<"0"<<" "<<b-(k-a)<<endl;
       }
       else cout<<"0"<<" "<<"0"<<endl;
   }
}

/// A L H A M D U L I L L A H
