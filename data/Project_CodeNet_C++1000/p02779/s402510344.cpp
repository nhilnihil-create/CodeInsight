#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i,n) {
    int a;
    cin >> a;
    if(mp.count(a)) {
      cout << "NO" << endl;
      return 0;
    }else{
      mp[a] = 1;
    }
  }
  cout << "YES" << endl;
  return 0;
}