#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end

int k,q,d[5010];
void solve(){
   int n,x,m; scanf("%d%d%d",&n,&x,&m);
   ll last=x,res=n-1;
   rep(i,0,k){
      ll cnt=(n-i-1+k-1)/k;
      last+=cnt*(d[i]%m);
      if(d[i]%m==0)res-=cnt;
   }
   res-=(last/m-x/m);
   printf("%lld\n",res);
}

int main(){
   scanf("%d%d",&k,&q);
   rep(i,0,k)scanf("%d",&d[i]);
   rep(i,0,q)solve();
   return 0;
}
