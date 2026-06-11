#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned long long ull;
typedef long double ld;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265
const int MOD=1e9+7;


#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a)  (a).begin(),(a).end()

const int N=1e9+7;

int dp[100005];

int power(int a,int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%N;
    if(b%2==0)
    {
        int x=power(a,(b/2));
        x=(x*x)%N;
        return x;
    }
    else
    {
        int x=power(a,(b-1)/2);
        x=(x*x)%N;
        x=(x*a)%N;
        return x;
    }
}

int32_t main()
{
   IOS;
   int n,k;
   cin>>n>>k;

   for(int i=k;i>=1;i--)
   {
       dp[i]=power((k/i),n);
       for(int j=i*2;j<=k;j=j+i)
       {
           dp[i]=dp[i]-dp[j];
       }
   }

   int ans=0;
   for(int i=1;i<=k;i++)
   {
       ans=(ans+(dp[i]*i)%N)%N;
   }

   cout<<ans%N<<endl;



}













