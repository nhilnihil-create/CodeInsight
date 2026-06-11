#include <bits/stdc++.h>
using namespace std;


int main()
{
   int n,pos;
   int sum = 0;
   string str="", x="";
   int t;
   vector<string> s;
   vector<int> a;
   cin>>n;
   for(int i=0;i<n;i++)
   {
     cin>>str>>t;
     s.push_back(str);
     a.push_back(t);
   }
  
  cin>>x;

  for(int i=0;i<n;i++)
  {
    if(s[i]==x)
    pos = i;
  }

  for(int i=(pos+1);i<n;i++)
  {
     sum = sum + a[i];
  }
   
   cout<<sum<<endl;
   return 0;
   
}
