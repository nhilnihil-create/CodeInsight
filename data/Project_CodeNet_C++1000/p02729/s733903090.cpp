#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define f(n) for(int i = 0; i < n; ++i)
#define fa(a, n) for(int i = a; i < n; ++i)
#define fi(i, n) for(int i = 0; i < n; ++i)
#define mod 1000000007
#define oo 1000000000LL
int main()
{
    long long int n,m,sum=0,i;
   cin>>n>>m;
   for(i=n-1;i>=0;i--)
   {
       sum+=i;
   }
   for(i=m-1;i>=0;i--)
   {
       sum+=i;
   }
   cout<<sum<<endl;
    return 0;
}
