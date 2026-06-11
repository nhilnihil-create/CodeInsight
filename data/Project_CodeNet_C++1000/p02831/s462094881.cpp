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
const double PI=acos(-1);

int main() {
  ll a,b;
  cin>>a>>b;
  ll mx=max(a,b);
  for(ll i=mx;;i+=mx){
    if(i%a==0&&i%b==0){
      cout<<i<<endl;
      return 0;
    }
  }
}