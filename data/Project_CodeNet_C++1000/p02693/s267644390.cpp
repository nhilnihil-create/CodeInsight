#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;


int main() {
  int k, a, b;
  cin >> k >> a >> b;
  int c=k;
  while(k <= b){
    if((a <= k) && (k <= b)){
      cout << "OK" << endl;
      return 0;
    }
    k += c;
  }
    
  cout << "NG" << endl;
  return 0;
}
