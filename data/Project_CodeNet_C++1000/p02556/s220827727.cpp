#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;


int main(){
  int N;
  cin >> N;
  int max_X, min_X, max_Y, min_Y;
  max_X = 0;
  min_X = 2000000000;
  max_Y = -1000000000;
  min_Y = 1000000000;
  
  int x,y;
  for(int i = 0; i<N; i++){
    cin >> x >> y;
    max_X = max(max_X, x+y);
    min_X = min(min_X, x+y);
    max_Y = max(max_Y, x-y);
    min_Y = min(min_Y, x-y);
  }
  
  cout << max(max_X-min_X, max_Y-min_Y);
  
}