
                                 /*Bismillahir Rahmanir Rahim*/



#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define ll long long int
#define dd double
using namespace std;

int main()
{
   ll n,i,j,sum=0;
   cin>>n;
   for(i=1;i<=n;i++)
   {
      for(j=i;j<=n;j+=i)
      {
         sum+=j;
      }
   }
   cout<<sum<<endl;
}
//Apna Time Aayega :)