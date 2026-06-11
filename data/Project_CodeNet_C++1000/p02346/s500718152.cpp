#include <iostream>
#include <algorithm>

using namespace std;

//O(log n)
const int MAX_N = 100000;

//[1, n]
int n, bit[MAX_N + 1];

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
    bit[i] += x;
    i += i & -i;
  }
}

main(){
  int q;
  cin >> n >> q;
  fill(bit, bit+MAX_N+1, 0);
  for(int i=0;i<q;i++){
    int a, b, c;
    cin >> a >> b >> c;
    if(a) cout << sum(c) - sum(b-1) << endl;
    else add(b, c);
  }
}