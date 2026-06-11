#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include <map>
#include <string.h>
#include <vector>
#include <cmath>
#include <deque>
#include <iomanip>

using namespace std;
#define range(a) a.begin(), a.end()
#define rep(i, c) for(int i = 0; i < (int)c; i++)
typedef long long ll;

template <typename T> ostream& operator<<(ostream& out, vector<T> &v){
  for (int i = 0; i < (int)v.size(); i++) {
    out<<v[i]<<' ';
  }
  return out;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, d; cin >> m >> d;
  int ans= 0;
  for(int j = 1; j <= m; j++){
    for(int i = 10; i <= d; i++){
      int d_1 = i % 10, d_10 = i / 10;
      if(d_1 >= 2 && d_10 >= 2 && d_1 * d_10 == j){
        ans++;
        }
      }
    }
  cout << ans << endl;

  return 0;
}
