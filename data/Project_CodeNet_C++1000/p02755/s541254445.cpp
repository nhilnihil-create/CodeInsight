#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
int dh[4] = {-1, 0, 0, 1};
int dw[4] = {0, -1, 1, 0}; 
using P = pair<int, int>;
const double pi = acos(-1.0);

int main(){
  int a,b;
  cin>>a>>b;
  int ans;
  ans=10*b;
  Rep(i,ans,ans+10){
    if(i*8/100==a){cout<<i<<endl;return 0;}
  }
  cout<<-1<<endl;
    
    
  return 0;
}
