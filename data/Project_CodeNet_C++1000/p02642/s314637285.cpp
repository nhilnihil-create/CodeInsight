#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
vector<int>chk(N);
int main()
{
   int n,one=0;
   cin>>n;
   vector<int>a(n);
   for(int i=0;i<n;i++)
   {
       cin>>a[i],chk[a[i]]++;
       if(a[i]==1)one++;
   }
   if(one==1)cout<<1<<endl,exit(0);
   else if(one>1)cout<<0<<endl,exit(0);
   int ans=0;
   sort(a.begin(),a.end());
   for(int i=0;i<n;i++)
   {
       int f=1;
       for(int j=a[i];j<=N;j+=a[i])
        if(chk[j]==1&&f)ans++,f=0,chk[j]=0;
         else if(chk[j])chk[j]=0,f=0;

   }
   cout<<ans<<endl;
}
