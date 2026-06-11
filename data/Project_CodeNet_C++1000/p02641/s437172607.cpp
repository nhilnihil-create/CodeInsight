#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  int x,n;
  cin>>x>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  for(int i=0;;i++){
    bool ja=true;
    bool ja2=true;
    rep(j,n){
      if(x+i==a[j]){
        ja=false;
      }
      if(x-i==a[j]){
        ja2=false;
      }
    }
    if(ja2){
      cout<<x-i<<endl;
      return 0;
    }
    if(ja){
      cout<<x+i<<endl;
      return 0;
    }
  }
}