#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;


int main(){
  int H, W, M;
  cin >> H >> W >> M;
  
  
  
  vector<int> Hi(H, 0);
  vector<int> Wi(W, 0);
  set<pair<int,int>> bom;
  for(int i = 0; i<M; i++){
    int h,w;
    cin >> h >> w;
    Hi[h-1]++;
    Wi[w-1]++;
    bom.insert(make_pair(h-1,w-1));
  }
  
  
  int max_h = 0;
  int max_w = 0;
  
  for(int i = 0; i<H; i++){
    max_h = max(max_h, Hi[i]);
  }
  for(int i = 0; i<W; i++){
    max_w = max(max_w, Wi[i]);
  }
  
  
  
  vector<int> X(0);
  vector<int> Y(0);
  
  for(int i = 0; i<H; i++){
    if(Hi[i] == max_h){
      X.push_back(i);
    }
  }
  for(int i = 0; i<W; i++){
    if(Wi[i] == max_w){
      Y.push_back(i);
    }
  }
  
  const int xx = X.size();
  const int yy = Y.size();
  
  if(xx*yy>M){
    cout << max_h+max_w << endl;
    return 0;
  }
  else{    
    for(auto p: X){
      for(auto q: Y){
        if(bom.find(make_pair(p,q))==bom.end()){
          cout << max_h+max_w << endl;
          return 0;
        }
      }
    }
  }
  cout << max_h+max_w-1 << endl;
  return 0;
}

      
      
       



