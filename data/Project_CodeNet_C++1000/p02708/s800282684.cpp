#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define fi(i,a,b) for(ll i=a-1;i>=b;i--)
#define endl '\n'
#define spc " "
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.14159265358979323
#define sz(a) (int)((a).size())
#define len(a) (int)(a.length())
#define FOR(i,j,k,l) for(ll i=j;i<k;i+=l)
#define CC(x) cout<<x<<endl


void Fast_IO() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   #ifndef ONLINE_JUDGE
   freopen("input.in","r",stdin);
   freopen("output.out","w",stdout); 
   #endif
} 

int main(){
   Fast_IO();
   ll n,k;
   cin>>n>>k;
   ll ans=0,maxi,mini;
   f(i,k,n+1){
      maxi = (n*(n+1))/2;
      maxi -= ((n-i+1)*(n-i))/2;
      mini = (i*(i-1))/2;
      ans=ans%mod;
      ans+= abs(maxi-mini+1)%mod;
   }
   CC(ans);
}

