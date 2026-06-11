//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>>vvi;
const ll MOD=1000000007LL;
int main(){
  ll m;
  cin>>m;
  vector<ll> d(m),c(m);
  rep(i,m)cin>>d[i]>>c[i];
  ll num=0;
  ll sum=0;
  rep(i,m){
    num+=c[i];
    sum+=d[i]*c[i];
  }
  if(sum%9==0)num--;
  cout<<num-1+sum/9<<endl;
}
    