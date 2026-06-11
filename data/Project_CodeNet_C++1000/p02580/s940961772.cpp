#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int H, W, M;
  cin >> H >> W >> M;
  vector<int> h(M,0),w(M,0);
  vector<int> x(H,0),y(W,0);
  set<pair<int,int>> v;
  rep(i,M){
    cin >> h[i] >> w[i];
    h[i]--; w[i]--;
    x[h[i]]++; y[w[i]]++;
    v.insert({h[i],w[i]});
  }

  int h_m = 0;
  rep(i,H) h_m = max(h_m, x[i]);
  int v_m = 0;
  rep(i,W) v_m = max(v_m, y[i]);

  vector<int> a;
  rep(i,H) if(x[i] == h_m) a.push_back(i);
  vector<int> b;
  rep(i,W) if(y[i] == v_m) b.push_back(i);  

   for(auto i : a){
    for(auto j : b){
       if(v.find({i,j}) == v.end()){
         cout << h_m + v_m << endl; 
         return 0;      
       }
     }
   }
  
  cout << h_m + v_m - 1 << endl;
  return 0;
}
