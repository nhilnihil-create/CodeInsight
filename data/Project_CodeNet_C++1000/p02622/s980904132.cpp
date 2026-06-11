#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main()
{
   string s1;
   string s2;

   cin >> s1>>s2;
   int counter=0;
   int n = s1.length();
   for(int i =0;i<n;i++)
   {
       if(s1[i]!=s2[i])
        counter++;
   }
   cout<<counter;
    return 0;
}
