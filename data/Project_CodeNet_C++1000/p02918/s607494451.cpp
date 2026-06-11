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

int main() {//LR・・RLの部分をひっくり返す。
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  //////////////
  int ans=0;//同じ文字が続いている回数
  int change=0;//l->r or r->l になっている回数
  rep(i,0,n-1){
    if(s[i]==s[i+1])ans++;
    else change++;
  }
  rep(i,0,k){
   if(change==0||change==1){
     ans=n-1;
     break;
   }
    else{
     ans+=2;
      change-=2;
    }
  }
  cout<<ans<<endl;
}