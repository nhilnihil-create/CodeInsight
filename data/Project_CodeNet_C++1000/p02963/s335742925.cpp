#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  ll s; cin >> s;
  ll a=1e9,b=1;
  ll x=1e9;
  ll c=s%x==0?0:x-s%x;
  ll d=c==0?s/x:s/x+1;
  cout << 0 << " " << 0 << " " << a << " " << b << " " << c << " " << d << endl;
  
}