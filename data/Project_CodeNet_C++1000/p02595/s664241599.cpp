#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

struct Point{
   long x, y;
};

int main(){
   set<Point> points;
   long N,D;
   cin>>N>>D;
   long count = 0;
   for(int i=0; i<N; i++){
      long x, y; cin>>x>>y;
      double d = sqrt(x*x+y*y);
      if(d <= D) count++;
   }

   cout << count << endl;
}