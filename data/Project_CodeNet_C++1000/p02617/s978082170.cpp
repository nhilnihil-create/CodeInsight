#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end



int main(){
   int n; cin>>n;
   ll res=0;
   rep(i,0,n)res+=1LL*(i+1)*(n-i);
   rep(_,0,n-1){
      int lb,rb; cin>>lb>>rb; lb--; rb--;
      if(lb>rb)swap(lb,rb);
      res-=1LL*(lb+1)*(n-rb);
   }
   cout<<res<<endl;
   return 0;
}