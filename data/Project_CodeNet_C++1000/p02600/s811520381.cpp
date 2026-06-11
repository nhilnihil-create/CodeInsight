#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int x;
  cin>>x;
  if(400<=x&&x<600)cout<<8<<endl;
  if(600<=x&&x<800)cout<<7<<endl;
  if(800<=x&&x<1000)cout<<6<<endl;
  if(1000<=x&&x<1200)cout<<5<<endl;
  if(1200<=x&&x<1400)cout<<4<<endl;
  if(1400<=x&&x<1600)cout<<3<<endl;
  if(1600<=x&&x<1800)cout<<2<<endl;
  if(1800<=x&&x<2000)cout<<1<<endl;
}