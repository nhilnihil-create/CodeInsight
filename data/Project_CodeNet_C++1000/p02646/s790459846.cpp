#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int lli;
int main()
{
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   lli a,b,v,w,t;
   cin>>a>>v;
   cin>>b>>w;
   cin>>t;
   if(abs(a-b)<=(v-w)*t)
   cout<<"YES"<<"\n";
   else
   cout<<"NO"<<"\n";
}