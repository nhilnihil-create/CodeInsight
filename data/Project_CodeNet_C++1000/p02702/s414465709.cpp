/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
   string s;
   cin>>s;
   int n=s.length();
   vector<int>v(2019);
   int mod=2019;
   int ans=0,sum=0,p=1;
   v[sum]++;
   for(int i=n-1;i>=0;i--)
   {
       int digit=s[i]-'0';
       sum=(sum+digit*p)%mod;
       p=(p*10)%mod;
        ans+=v[sum];
       v[sum]++;
   }
   
   cout<<ans;

    return 0;
}
