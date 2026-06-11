//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

int main(){
  int h,w,m; cin >> h >> w >> m;
  set<pii> bomb;
  vector<ll> tate(h);
  vector<ll> yoko(w);
  ll tatemx=0;
  ll yokomx=0;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    tate[a]++; yoko[b]++;
    chmax(tatemx,tate[a]);
    chmax(yokomx,yoko[b]);
    bomb.insert(pii(a,b));
  }
  /*
  ll ans=0;
  rep(i,m){
    chmax(ans,tate[bomb[i].first]+yoko[bomb[i].second]);
  }
  cout << ans-1 << endl;
  */
  vector<int> tatekoho(0);
  vector<int> yokokoho(0);
  rep(i,h){
    if(tate[i]==tatemx) tatekoho.push_back(i);
  }
  rep(i,w){
    if(yoko[i]==yokomx) yokokoho.push_back(i);
  }
  if(tatekoho.size()*yokokoho.size()>m){
    cout << tatemx+yokomx << endl;
    return 0;
  }
  bool f=1;
  rep(i,tatekoho.size()){
    rep(j,yokokoho.size()){
      if(!(bomb.count(pii(tatekoho[i],yokokoho[j])))) f=0;
    }
  }
  if(f) cout << tatemx+yokomx-1 << endl;
  else cout << tatemx+yokomx << endl;
}