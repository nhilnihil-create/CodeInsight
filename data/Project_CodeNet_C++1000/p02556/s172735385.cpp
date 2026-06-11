//Tonight's the night and it is going to happen again and again.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define T ll t; cin>>t; while(t--)
#define mod 1000000007
#define inf 1000000000000000000
#define mem(name,val) memset(name,val,sizeof(name))
#define f(n) for(ll i=0;i<n;i++)
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define endl "\n"
ll gcd(ll a,ll b){if(b==0){return a;}return gcd(b,a%b);}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif
   ll n;
   cin>>n;ll a[n],b[n];ll max1=-inf,max2=-inf,max3=-inf;ll min1=inf;
   f(n)
   {
    cin>>a[i]>>b[i];
    max1=max(max1,a[i]+b[i]);
    min1=min(min1,a[i]+b[i]);
    max2=max(max2,a[i]-b[i]);
    max3=max(max3,b[i]-a[i]);
   }
   cout<<max(max1-min1,max2+max3);
   //max(abs(a[i]-a[j])+abs(b[i]-b[j]))
}