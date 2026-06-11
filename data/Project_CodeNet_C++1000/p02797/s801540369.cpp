#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n,k,s;
  cin >> n >> k >> s;
  rep(i,k) cout << s << " ";
  if(s != 1e9) s++;
  else s--;
  rep(i,n-k){
    cout << s;
    if(i != n-k-1) cout << " ";
    else cout << "" << endl;
  }
}