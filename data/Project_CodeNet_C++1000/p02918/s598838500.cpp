#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }

int main(void){
  int n,k; cin >> n >> k;
  string s; cin >> s;
  int boundary_num = 0;
  rep(i,s.size()-1){
    if(s.at(i) != s.at(i+1)){
      boundary_num++;
    }
  }
  if(boundary_num/2+boundary_num%2 <= k){
    cout << s.size() - 1 << endl;
  }
  else{
    cout << s.size()-1-boundary_num+2*k << endl;
  }
  return 0;
}
