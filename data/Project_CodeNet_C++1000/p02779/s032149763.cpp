#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n;
  cin >>n;
  set<int> a;
  rep(i,n){
    int z;
    cin >> z;
    a.insert(z);
  }
  if(n==(int)a.size()) cout << "YES" << endl;
  else cout<< "NO" << endl;
  return 0;
}
