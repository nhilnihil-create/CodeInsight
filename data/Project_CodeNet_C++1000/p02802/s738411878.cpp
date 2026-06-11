#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  M mm;
  int ac = 0, wa = 0;
  int q;
  string r;
  rep(i, m){
    cin >> q >> r;
    if(mp[q] == 0){
      if(r == "AC"){
        wa += mm[q];
        mp[q]++;
        ac++;
      }
      else{
        mm[q]++;
      }
    }
  }
  cout << ac << " " << wa << endl;
      
    
  return 0;
}
