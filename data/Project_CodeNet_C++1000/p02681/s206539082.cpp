#include <bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
    int i,k=0;
   string s,t;
   cin>>s>>t;
   for(i=0;i<s.size();i++)

   {
       if(s[i]!=t[i])
    k++;
   }
   if(k>0)
    cout<<"No"<<endl;
   else
    cout<<"Yes"<<endl;
   return 0;
}
