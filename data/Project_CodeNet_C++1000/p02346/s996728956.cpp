#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_N = (1 << 17);

int bit[MAX_N+1], n;

int sum(int i){
  int s = 0;
  while(i > 0){
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int x){
  while(i <= n){
    bit[i] = bit[i] + x;
    i = i + (i & -i);
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int _n, q; cin >> _n >> q;
  //initialize
  n=1;
  while(n < _n){
    n = n*2;
  }
  for(int i=1;i<=n;i++){
    bit[i]=0;
  }
  for(int i=0;i<q;i++){
    int com, x, y;
    cin >> com >> x >> y;
    if(com == 0){
      add(x, y);
    }else{
      if(x == 1) cout << sum(y) << endl;
      else cout << sum(y) - sum(x-1) << endl;
    }
  }
}
