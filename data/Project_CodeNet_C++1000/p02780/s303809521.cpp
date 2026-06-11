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
  int n,k;
  cin>>n>>k;
  vector<int> p(n), q(n); //q[i],,, i番目までの数の合計
  rep(i,n) {
    cin>>p[i];
    if(i>0) q[i]=q[i-1]+p[i]+1;
    else q[0]=p[0]+1;
   // cout<<q[i]<<endl;
  }
  
  int ans2=0;

  for(int i=0;i<=n-k;i++){//K個の最初の座標．
    int now2;
    if(i==0){
      now2=q[k-1];
    }else{
      now2=q[i+k-1]-q[i-1];      
    }
    ans2=max(now2,ans2);
  }
  
  printf("%f",double(ans2)/2.0);
  return 0;
  
    
    

    
  
}
