#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;
 
signed main() {
  int N;
  cin >> N;
  
  map<int, int> num;
  for( int i = 0; i < N; i++ ){
    int A;
    cin >> A;
    if( num.count(A) ) num.at(A)++;
    else num[A] = 1;
  }
  
  bool fg = true;
  if( num.size() > 3 ) fg = false;
  else if( num.size() == 3 ){
    vector<int> suzi(6);
    int cnt = 0;
    for( auto p : num ){
      suzi.at(cnt) = p.first;
      suzi.at(cnt+3) = p.second;
      cnt++;
    }
    int y = suzi.at(0)^suzi.at(1)^suzi.at(2);
    if( y != 0 || suzi.at(3) != suzi.at(4) || suzi.at(4) != suzi.at(5) ){
      fg = false;
    }
  }else if( num.size() == 2 ){
    if( !num.count(0) ) fg = false;
    else if( num.at(0) != N/3 ) fg = false;
  }else if( num.size() == 1 ){
    if( !num.count(0) ) fg = false;
  }
  if( fg ) cout << "Yes" << endl;
  else cout << "No" << endl;
}