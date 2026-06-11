#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n,r;
  cin >> n >> r;
  if(n>=10){
    cout << r << endl;
    return 0;
  }
  cout << r+100*(10-n) << endl;
  return 0;
}
