
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
   ll a,b,c;
   cin>>a>>b>>c;
   ll t=min(a,c),ak=0;
   c-=t;
   a-=t;
   if(c>0)
   {
     ak=min(c,b);
   }
   b-=ak;
   cout<<a<<" "<<b<<endl;

    

}
//Apna Time Aayega :)