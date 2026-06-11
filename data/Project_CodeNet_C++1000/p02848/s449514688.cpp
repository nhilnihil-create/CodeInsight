#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,y,i,m=1,p;
   string s;
   cin>>n>>s;
   int l=s.size();
  for(i=0;i<l;i=i+1)
   {
       p=s[i]-'A';
       p=p+n;
       p=p%26;
      s[i]=p+'A';
       cout<<s[i];


   }
    cout<<endl;
    return 0;
}
