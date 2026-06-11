#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n,k;
  cin >> n >> k;
  int i=0;
  while(n){
    n/=k;
    ++i;
  }
  cout << i << endl;
  return 0;
}
