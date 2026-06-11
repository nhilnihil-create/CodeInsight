/*
  GOOD is not Enough
  You've got to be GREAT.
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define mod 1000000007
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i++)
#define fr(i,k,n) for(int i=k;i>=n;i--)
#define pb push_back
#define pii pair<int,int>
#define dbg(x) cout << (#x) << " is " << (x) << '\n' 
#define F first
#define S second
#define sz(x) (int)(x).size()
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

void solve()
{
   int n;
   cin >> n;
   int a[n+1],tot=0;
   f(i,n+1)
    cin >> a[i],tot+=a[i];
   int flg=0;
   int len=0,ans=0;
  
   f(i,n+1)
   {
       if(i==0)
        len=(1-a[i]);
       else
       {
         tot-=a[i];
         len=min(tot,(2*len)-a[i]);
       } 
       ans+=(len+a[i]);
      //  dbg(len);
       if(len<0)
       {
           cout << "-1\n";return;
       }
   }
   cout << ans << '\n';
    return;
} 

signed main()
{
  FAST
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}