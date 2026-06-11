#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,k;
  cin >> n >> k;
  vector<bool> snuke(n,false);
  rep(i,k){
    int d;
    cin >> d;
    rep(i,d){
      int a;
      cin >> a;
      snuke[a-1] = true;
    }
  }
  int cnt;
  rep(i,n){
    if(snuke[i] == false)cnt++;
  }
  cout << cnt << endl;
}