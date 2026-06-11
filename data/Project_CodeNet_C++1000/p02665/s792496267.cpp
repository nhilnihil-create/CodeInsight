#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3LL;
const int mod = (int)1e9 + 7;
using namespace std;
#if LOCAL
#include "../../tr.h"
#else
#define tr(...)
#define endl '\n'
#endif
template<class T, class T2> void smin(T& a, T2 val) {if (a > val) a = val;}template<class T, class T2> void smax(T& a, T2 val) {if (a < val) a = val;}
const int N = 5*(int)1e5 + 10;

int n, a[N], total[N], suffix[N];

int32_t main(){_
   
   cin>>n;

   for (int i = 0; i <= n; ++i)
   {
      cin>>a[i];
   }

   total[0] = 1;
   for (int i = n; i >= 0; --i)
   {
      suffix[i] = suffix[i+1] + a[i];
   }

   int ans = 1;
   for (int i = 1; i <= n; ++i)
   {
      total[i] = min((total[i-1] - a[i-1]) * 2, suffix[i]);
      if (total[i] < a[i]){
         cout<<-1;
         exit(0);
      }
      ans += total[i];
   }

   if (total[0] < a[0]){
      cout<<-1;
      exit(0);
   }
      
   cout<<ans;

   return 0;
}