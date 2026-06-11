#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  int h,w,a,b;cin >>h>>w>>a>>b;
  int m[h][w];
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if(i<b){
        if(j<a){
          m[i][j] = 1;
        } else {
          m[i][j] = 0;
        }
      } else {
        if(j<a){
          m[i][j] = 0;
        } else {
          m[i][j] = 1;
        }
      }
    }
  }
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      cout << m[i][j];
    }
    cout << endl;
  }
  return 0;
}
