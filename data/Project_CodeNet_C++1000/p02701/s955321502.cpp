//BISMILLAH
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int a,b,c,d,minus1,minus2,res=0;
   int n;
   int flag=n;
   set<string>s;
   cin>>n;
   while(n--)
   {
       string str;
       cin>>str;
       s.insert(str);

   }
   res=s.size();
   cout<<res<<endl;
}
