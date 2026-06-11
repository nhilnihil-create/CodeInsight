#include <bits/stdc++.h>
using namespace std;

#define Pb push_back
#define Mp make_pair
#define ff first
#define ss second
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define db1(x) cout<<#x<<" : "<<x<<endl;
#define db2(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define db3(x,y,z) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<endl;

typedef long long int ll;
typedef long double ld;

const int  N = 1e5+5;
const int inf = INT_MAX;
const int MOD = 1e9+7;


void solve()
{
   ll a,b,v,w,t;
   cin >> a >> v >> b >> w >> t;
   ll d1 = abs(a-b);
   ll d2 = (v-w)*1LL*t;
   if(d1<=d2)
   {
      cout << "YES";
   }
   else
   {
      cout << "NO";
   }
}

int32_t main()
{
   IOS;
   //freopen("input.txt", "rt", stdin);
   //freopen("output.txt", "wt", stdout);
   int t=1;
   //cin >> t;
   for(int i=1;i<=t;i++)
   {
      //cout<<"Case #"<<i<<": ";
      solve();
   }
   return 0;
}
/*==============================================================================================================================================================*/
