#include<bits/stdc++.h>
using namespace std;
#define int long long
void Digvijay()
{
   int n;
   cin>>n;
   vector<int> a(n);
   for(auto& it:a)cin>>it;
   int val=1;
   bool ok=false;
   for(int i=0;i<n;i++)
   {
       if(a[i]==val)
       {
           ok=true;
           val++;
       }
   }
   if(ok)
   {
       cout<<n-val+1<<"\n";
   }
   else
   {
       cout<<-1<<"\n";
   }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    //cin>>_;
    for(int __=0;__<_;__++)
    {
        Digvijay();
    }
}