#include<bits/stdc++.h>
using namespace std;


int main()
{
   int n;
   cin>>n;
   string s, ck1, ck2;
   cin>>s;
   if(n&1) cout<<"No\n";
   else
   {
       int x=n/2;
       ck1=s.substr(0, x);
       ck2=s.substr(x, n);
       if(ck1==ck2) cout<<"Yes\n";
       else cout<<"No\n";
   }
}



