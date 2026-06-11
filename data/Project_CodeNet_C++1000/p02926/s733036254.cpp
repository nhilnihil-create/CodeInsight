#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<iomanip>
#include<set>
#include<bitset>
#include<cmath>
#include<numeric>
#include<limits>

#define REP(i, m, n) for(int i = (m); i < (n); i++)
#define rep(i,n) REP(i,0,n)
#define NIL -1
using namespace std;
// typedef long long ll;
static const int MOD = 10000007;
static const int MAX = 1005;
int N, M[MAX];
int A[MAX][MAX], T[MAX], step[MAX];


using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> xs(n),ys(n);
  for(Int i=0;i<n;i++) cin>>xs[i]>>ys[i];
  double ans=0;
  for(Int i=0;i<n;i++){
    Int gx=xs[i],gy=ys[i];
    for(Int k=0;k<4;k++){
      {
        Int nx=-gy,ny=gx;
        gx=nx;
        gy=ny;
      }

      Int sx=0,sy=0;
      Int px=0,py=0;
      Int qx=0,qy=0;

      // auto hoge = [](int huga, int hugi) {return huga + hugi} はラムダ式
      // [&]は参照渡し、[=]なら値渡し（全ての変数について）
      auto dot=[&](Int x1,Int y1,Int x2,Int y2){return x1*x2+y1*y2;}; // 内積
      auto cross=[&](Int x1,Int y1,Int x2,Int y2){return x1*y2-x2*y1;}; // 外積
      for(Int j=0;j<n;j++){
        Int res=dot(xs[j],ys[j],gx,gy);
        if(res<0) continue;
        if(res>0){ // 内積が正なら近い向き
          sx+=xs[j];
          sy+=ys[j];
          continue;
        }
        // 内積が0の時はどちらの方向で直行しているか？
        if(cross(xs[j],ys[j],gx,gy)>0){ // 外積が正ならgはsの時計回り側
          px+=xs[j];
          py+=ys[j];
        }else{ // sを反時計回りに回してgになる
          qx+=xs[j];
          qy+=ys[j];
        }
      }
      // 内積が0のベクトルを足したり足さなかったりを試す。
      // t = 0 : 時計回り＝なし、反時計回り＝なし
      // t = 1 : 時計回り＝あり、反時計回り＝なし
      // t = 2 : 時計回り＝なし、反時計回り＝あり
      // t = 3 : 時計回り＝あり、反時計回り＝あり
      for(Int t=0;t<4;t++){
        double bx=sx,by=sy;
        if(t&1) bx+=px,by+=py; // & is bitwise operator
        if(t&2) bx+=qx,by+=qy; // & represents "and". t&2 is the 2nd least bit.
        chmax(ans,bx*bx+by*by);
      }
    }
  }

  cout<<fixed<<setprecision(12)<<sqrt(ans)<<endl;
  return 0;
}
