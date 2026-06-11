#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int>vi;
#define pb push_back
#define sc(n) scanf("%d",&n)
#define lsc(n) scanf("%lld",&n)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(i=0LL;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define rev1(i,n) for(i=n;i>0;i--)
#define in insert
#define IT ::iterator
#define pr(n) printf("%d\n",n)
#define lpr(n) printf("%lld\n",n);

int main()
{
   ll k,n,i;
   cin >> k >> n;
   ll a[n],b[n],c[n];
   rep(i,n)
   {
   	cin >> a[i];
   }
   rep(i,n)
   {
   	if(i==0)b[i]=k-(k-a[n-1]+a[0]);
   	else b[i]=k-(a[i]-a[i-1]);
   }
   
   sort(b,b+n);
   
   cout << b[0];
}
