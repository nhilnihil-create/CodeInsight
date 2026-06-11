#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  if(S.at(0)=='S')
   {
       if(S.at(1)=='U')
       cout << 7 <<endl;
       else
       {
        cout << 1<< endl;
       }  
   }
     if(S.at(0)=='T')
   {
       if(S.at(1)=='U')
       cout << 5 <<endl;
       else
       {
        cout << 3<< endl;
       }  
   }
   if(S.at(0)=='W')
   {
       cout << 4 <<endl;
   }
   if(S.at(0)=='M')
   {
       cout <<6 <<endl;
   }
   if(S.at(0)=='F')
   {
       cout <<2<<endl;
   }
}