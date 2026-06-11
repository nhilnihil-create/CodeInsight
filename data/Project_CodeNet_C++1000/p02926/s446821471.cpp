#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define pb push_back
#define sz(i) (int)(i.size())
#define F first
#define S second
#define L long double
#define P pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3LL;
const int mod = (int)1e9 + 7;
using namespace std;
#if LOCAL
#include "../../tr.h"
#else
#define tr(...)
#define endl '\n'
#endif
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}
const int N = 5*(int)1e5 + 10;

int n, a[N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}
//shuffle(v.begin(), v.end(), rng);

int dist(int x, int y){
   return (x) * (x) + (y) * (y);
}

int32_t main(){_

   cin>>n;

   vector<P> v;
   
   for (int i = 0; i < n; ++i)
   {
      int x, y;
      cin >> x >> y;
      v.push_back({x, y});
   }

   int ans = 0;
   for (int i = 0; i < N; ++i)
   {
      shuffle(v.begin(), v.end(), rng);      
      int X = 0, Y = 0;
      for (int j = 0; j < sz(v); ++j)
      {
         if(dist(X+v[j].F, Y+v[j].S) > dist(X, Y)){
            X += v[j].F;
            Y += v[j].S;
         }  
      }
      smax(ans, dist(X, Y));
   }

   cout << fixed << setprecision(15);
   cout<<sqrtl(ans);   

   return 0;
}