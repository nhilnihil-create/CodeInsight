#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int m[2],d[2];
  rep(i,2) cin >> m[i] >> d[i];
  if(m[0] == m[1]) cout << "0" << endl;
  else cout << "1" << endl;
  return 0;
}