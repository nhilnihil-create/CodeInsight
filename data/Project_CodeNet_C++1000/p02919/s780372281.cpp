#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i],a[i]--;
  vector<int> idx(n);
  rep(i,n) idx[a[i]] = i; //各数字の位置を記録
  set<int> s;
  ll ans = 0;
  for(int x = n-1; x >= 0; x--){
    int i = idx[x]; //xの位置を取得
    ll c = 0;
    
    s.insert(i); //setにxの位置を入れる
    vector<int> l(2,-1),r(2,n);
    
    auto it = s.find(i);
    rep(j,2){
      if(it == s.begin()) break;
      it--;
      l[j] = *it;
    }
    
    it = s.find(i);
    rep(j,2){
      it++;
      if(it == s.end()) break;
      r[j] = *it;
    }
    vector<int> ls(2),rs(2);
    ls[0] = i-l[0]; ls[1] = l[0]-l[1];
    rs[0] = r[0]-i; rs[1] = r[1]-r[0];
    c = (ll)ls[0]*rs[1]+(ll)ls[1]*rs[0];
    
    ans += c*(x+1);
  }
  
  cout << ans << endl;
  
  return 0;
}
