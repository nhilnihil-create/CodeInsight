#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int k,x; cin >> k >> x;

  for(int i = x-(k-1);i<=x+(k-1);i++){
    cout << i << " ";
  }
  cout << endl;
  
  return 0;
}
