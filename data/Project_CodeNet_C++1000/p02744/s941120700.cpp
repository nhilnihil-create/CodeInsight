#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
  int n;
  cin >> n;
  vector<vector<string>> ans(n, vector<string>(0));
  ans.at(0).push_back("a");
  for(int i=0; i<n-1; i++){
    rep(j, ans.at(i).size()){
      int ia = 0;
      int ib = 0;
      int ic = 0;
      int id = 0;
      int ie = 0;
      int iff = 0;
      int ig = 0;
      int ih = 0;
      int ii = 0;
      int ij = 0;
      rep(l, ans.at(i).at(j).size()){
        if(ans.at(i).at(j).at(l) == 'a') ia = 1;
        if(ans.at(i).at(j).at(l) == 'b') ib = 1;
        if(ans.at(i).at(j).at(l) == 'c') ic = 1;
        if(ans.at(i).at(j).at(l) == 'd') id = 1;
        if(ans.at(i).at(j).at(l) == 'e') ie = 1;
        if(ans.at(i).at(j).at(l) == 'f') iff = 1;
        if(ans.at(i).at(j).at(l) == 'g') ig = 1;
        if(ans.at(i).at(j).at(l) == 'h') ih = 1;
        if(ans.at(i).at(j).at(l) == 'i') ii = 1;
        if(ans.at(i).at(j).at(l) == 'j') ij = 1;
      }
      int k = ia + ib + ic + id + ie + iff + ig + ih + ii + ij;
      rep(m, k+1){
        if(m == 0) ans.at(i+1).push_back(ans.at(i).at(j)+'a');
        if(m == 1) ans.at(i+1).push_back(ans.at(i).at(j)+'b');
        if(m == 2) ans.at(i+1).push_back(ans.at(i).at(j)+'c');
        if(m == 3) ans.at(i+1).push_back(ans.at(i).at(j)+'d');
        if(m == 4) ans.at(i+1).push_back(ans.at(i).at(j)+'e');
        if(m == 5) ans.at(i+1).push_back(ans.at(i).at(j)+'f');
        if(m == 6) ans.at(i+1).push_back(ans.at(i).at(j)+'g');
        if(m == 7) ans.at(i+1).push_back(ans.at(i).at(j)+'h');
        if(m == 8) ans.at(i+1).push_back(ans.at(i).at(j)+'i');
        if(m == 9) ans.at(i+1).push_back(ans.at(i).at(j)+'j');
      }
    }
  }
  rep(i, ans.at(n-1).size()) cout << ans.at(n-1).at(i) << endl;
  return 0;
}