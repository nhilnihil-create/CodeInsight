#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const int INF=1e9;


int main(){
  int h,n;
  cin>>h>>n;
  vector<int> a(n),b(n);
  vector<int> dps(h+1);
  
  rep(i,n){
     cin>>a[i];
     cin>>b[i];
   }

  rep(i,h){
    dps[i]=INF;
  }
  
  dps[h]=0;

  for(int h2=h;h2>=0;h2--){//体力を1ずつ減らして考える．
    rep(i,n){//魔法iを使用する場合．
      if(h2-a[i]<0){
        dps[0]=min(dps[0],dps[h2]+b[i]);
      }else{
        dps[h2-a[i]]=min(dps[h2-a[i]],dps[h2]+b[i]);
      }
    }
  }
  cout<<dps[0]<<endl;
}
