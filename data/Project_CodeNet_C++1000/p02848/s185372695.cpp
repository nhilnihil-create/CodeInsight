#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
   string s; int i,t, k;
   cin>>k>>s;
   if(k==0) cout<<s;
   else
   {
       for(i=0;i<s.size();i++)
       {
           if( (char) s[i]+k <='Z')
           {
               s[i]=s[i]+k;
           }
           else
           {
              t=64 + (k-( 'Z'-s[i]));
               s[i]=  (char)t;
           }
       }
       cout<<s<<endl;
   }

}
