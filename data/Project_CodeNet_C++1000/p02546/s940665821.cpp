#include<bits/stdc++.h>
using namespace std;
 int main()
 {
   string s;
   cin>>s;
   
   if(s[s.length()-1]=='s')
   {
     s.push_back('e');
     s.push_back('s');
   }
   else
   {
     s.push_back('s');
   }
   
   cout<<s<<"\n";
   return 0;
 }