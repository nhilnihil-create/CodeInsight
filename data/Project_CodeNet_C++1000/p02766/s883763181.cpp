#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  int n,k; cin >> n >> k;
  int beki = 1;
  int i = 1;
  for(i = 1; true; i++){
    beki*=k;
    //cout << beki << endl;
    if(beki > n) break;
  }

  cout << i << endl;
}
