#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
 int n;
 cin>>n;
 vector<int> a(n+1,0);
 for(ll i=1;i<=n;i++)
 {
     for(int j=0;j<=n;j+=i)
     {
         a[j]++;
     }
 }
 ll sum=0;
 for(ll i=1;i<=n;i++)
 {
     sum+=a[i]*i;
 }
 cout<< sum<<endl;
   return 0;
}
