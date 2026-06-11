#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
   string str,str1,str2;
   cin>>str>>str1;
   cin>>m>>n;
   cin>>str2;
   if(str==str2)
   {
      cout<<m-1<<" "<<n<<endl;

   }
   else if(str1==str2)
   {
       cout<<m<<" "<<n-1<<endl;
   }

 return 0;
}

