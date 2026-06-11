#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n,x;
cin >> n >> x;
vector<int> l(n);
rep(i,n) cin >> l.at(i);
int d = 0,cnt = 1;

rep(i,n){
  d += l.at(i);
  if(d <= x) cnt++;
  else break;
}

cout << cnt << endl;
}
  
