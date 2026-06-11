#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


int main()
{
   string str;
   cin>>str;
   bool flag = true;
   for(int i=0;i<str.length()-1;i++)
      if(str[i] == str[i+1])
      {
         flag = false;
         break;
      }
   if(flag)
      cout<<"Good";
   else
      cout<<"Bad";

   return 0;
}
