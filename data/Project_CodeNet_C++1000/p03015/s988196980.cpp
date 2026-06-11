#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
  string l;
  cin>>l;
  int64_t o,x;
  reverse(all(l));
  if(l.at(0)=='0'){
      o=1; x=2;
  }
  else{
      o=3; x=0;
  }
  rep(i,l.size()-1){
      if(l.at(i+1)=='0'){
          x=(2*o+3*x)%MOD;
      }
      else{
          o=(3*o+x)%MOD;
          x=2*x%MOD;
      }
  }
  cout<<o<<endl;
}