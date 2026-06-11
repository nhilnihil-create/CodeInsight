#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  map<string, int> M;
  rep(i,n) {
    string s;
    cin >> s;
    M[s]++;
  }
  int maxv = 0;
  for( auto&x: M){
    int v = x.second;
    if(v>maxv) maxv = v;
  }
  for(auto itr = M.begin(); itr != M.end();itr++){
    if(itr->second==maxv) cout << itr->first << endl;
  }
  return 0;
}
