#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"







int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

   string a,b;
   string ans;
   cin>>a>>b;
   for(int i=0;i<n;i++)
   {
          ans+=a[i];
          ans+=b[i];

   }
   cout<<ans<<endl;







}