#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   int i = min(n,m);
   int j = max(n,m);
   char a = (char) (i+48);
   string s = "";
   for(int k=0;k<j;k++){
       s=s+a;
   }
   cout<<s<<endl;
   return 0;
}