#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll INF=1e18;
const int MOD=1e9+7;
const double pi=acos(-1);


int main(){
  ll h,w,a,b;
  cin >> h >> w >> a >> b;
  rep(i,b){
    rep(j,w){
      if(j<a){
        cout <<0;
      }
      else cout<<1;
    }
    cout<<endl;
  }
  rep(i,h-b){
    rep(j,w){
      if(j<a){
        cout <<1;
      }
      else cout<<0;
    }
    cout<<endl;
  }
    
}
