#include<bits/stdc++.h>

using namespace std;

#define FOR(a,b,c) for(int a=b, __c=c; a<=__c; ++a)
#define FORD(a,b,c) for(int a=b, __c=c; a>=__c; --a)
#define forv(a,b) for(auto &a:b)

#define ii pair<int,int>
#define fi first
#define se second
#define all(a) begin(a),end(a)
#define reset(f,x) memset(f,x,sizeof(f))
#define pb push_back
#define eb emplace_back
#define fasty ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

#define bit(x,i) (x>>(i-1)&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))

const int N=2e5+5;
int n;
ii p[N];

int32_t main(){
   fasty;

   #define task "point"
   if(fopen(task".in", "r")) freopen(task".in", "r", stdin);

   cin>>n;
   FOR(i,1,n) cin>>p[i].fi>>p[i].se;

   vector<int> x,y;
   FOR(i,1,n){
      x.pb(p[i].fi-p[i].se);
      y.pb(p[i].fi+p[i].se);
   }
   sort(all(x)); sort(all(y));
   cout<<max(x.back()-x[0], y.back()-y[0]);
}
