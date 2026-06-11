#include <bits/stdc++.h>
using namespace std;
typedef bool boool;
typedef long long ll;
#define vl vector<ll>
#define vb vector<boool>
#define vs vector<string>
#define vp vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define rep1(i, n) for (long long i=0; i<(long long)(n); i++)
#define rep2(i, s, e) for (long long i=(s); i<(long long)(e); i++)
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

int main(){
  int h, w, m;
  cin >> h >> w >> m;
  map<int, int> row;
  map<int, int> col;
  vector<map<int, int>> vec(300000);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    row[a]++;
    col[b]++;
    vec[b][a]++;
  }
  int br = 0, bc = 0;
  vector<int> y, x;
  for(auto p : row){
    if(br<p.second){
      br = p.second;
      y.clear();
      y.push_back(p.first);
    }else if(br==p.second) y.push_back(p.first);
  }
  for(auto p : col){
    if(bc<p.second){
      bc = p.second;
      x.clear();
      x.push_back(p.first);
    }else if(bc==p.second) x.push_back(p.first);
  }
  for(auto dy : y){
    for(auto dx : x){
      if(vec[dx][dy] == 0){
        cout << br+bc << endl;
        return 0;
      }
    }
  }
  cout << br+bc-1 << endl;
  return 0;
}
    
    
