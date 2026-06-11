#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
   string s,t;
   cin>>s>>t;
   for(char ch='a';ch<='z';ch++)
   {
       if(s+ch==t)
       {
           cout<<"Yes"<<endl;
           return 0;
       }

   }
     cout<<"No"<<endl;



}





