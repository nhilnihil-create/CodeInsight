#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll Nmax=1e9;
const double pi=acos(-1);


//基本的に勝つ手をだす．
//勝つ手がなければ，K回後に勝つ手以外を出す．

int main(){
  long double a,b,x;
  cin>>a>>b>>x;

  if(x>=a*a*b/2){
     double ans=atan((a*a*b-x)*2/(a*a*a))*180/pi;
    printf("%.10f\n",ans);


  }else{
     double ans=atan(a*b*b/2/x)*180/pi;
    printf("%.10f\n",ans);


  }



}
