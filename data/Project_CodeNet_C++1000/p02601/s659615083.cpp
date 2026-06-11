#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;


int main() {
  int a,b,c,k;
  cin >> a>>b>>c>>k;
  rep(i,k){
    if(a<b&&b<c){
      cout <<"Yes"<<endl;
      return 0;
    }
    if(a>=b){
      b*=2;
      continue;
    }
    if(b>=c){
      c*=2;
      continue;
    }
  }
  if(a<b&&b<c){
      cout <<"Yes"<<endl;
      return 0;
  }
  cout << "No"<<endl;
}