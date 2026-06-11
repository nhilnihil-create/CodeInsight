#include<bits/stdc++.h>
using namespace std;
int main()
{
     string s[200005];
     long long n,i,count=1;
     cin>>n;
     for(i=1;i<=n;i++)
     {
         cin>>s[i];
     }
     sort(s+1,s+1+n);
     for(i=1;i<n;i++)
     {
         if(s[i]!=s[i+1])count++;
     }
     cout<<count<<endl;
     return 0;
}