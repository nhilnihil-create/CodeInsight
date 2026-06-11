#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
      // #ifndef ONLINE_JUDGE
      //  // for getting input from input.txt
      //  freopen("input.txt", "r", stdin);
      //  // for writing output to output.txt
      //  freopen("output.txt", "w", stdout);
      // #endif
       ll n,ans=0;
       cin>>n;
       vector<ll> a(n+2,0);
       vector<ll> b(n+1,0);
       for (int i = 1; i <= n+1; ++i)
       {
         cin>>a[i];
       }
       for (int i = 1; i <= n; ++i)
       {
         cin>>b[i];
       }
       for (int i = 1; i <= n; ++i)
       {
         ll v = min(a[i],b[i]);
         a[i] =a[i] -v;
         b[i] =b[i] -v;
         ll x = min(a[i+1],b[i]);
        a[i+1] = a[i+1] - x;
        b[i] = b[i] - x;
        ans = ans + (x+v );
       }

       cout<<ans<<endl;
	return 0;
}
