#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main()
{


      string s;
      long long q;
      cin>>s>>q;
      long long r=0;
      while(q--)
      {
         long long p;
         cin>>p;
         if(p==1)
         {
           r++;
         }
         else
         {
           long long n;
           char c;
           cin>>n>>c;
           if((n==1 && r%2==0) || ((n==2) && r%2==1))
            s=c + s;
           else
            s+=c;
         }
      }
      if(r%2==1)
      {
        reverse(s.begin(),s.end());
      }

      cout<<s<<endl;

}
