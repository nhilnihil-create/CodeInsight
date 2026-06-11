#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    int n;
    cin>>n;
   string s;
   cin>>s;
   int sum=0;
   int t=count(s.begin(),s.end(),'R');
   t=t-1;
   for(int i=0;i<=n;i++)
   {
       if(s[i]=='R')
       {
           if(i>t) sum++;
       }
   }
   cout<<sum<<endl;


   return 0;
}
