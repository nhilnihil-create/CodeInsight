#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<P> p(M); //firstでs,secondでcにアクセス
  rep(i,M)cin >> p[i].first >> p[i].second;
  
  rep(x,1000){
    int keta = 1;
    int nx = x/10;
    vector<int> d(1,x%10); //最初は１の位だけ入ってる
    while(nx){
      keta++;
      d.push_back(nx%10);
      nx /=10;
    }
    
    if(keta != N)continue;
    bool ok = true;
    reverse(d.begin(),d.end());
    rep(i,M){
      if(d[p[i].first -1] != p[i].second) ok = false;
    }
    if(ok){
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  
  
}
