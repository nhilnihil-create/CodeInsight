#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  rep(i,n) cin >> p[i];
  rep(i,n) cin >> q[i];
  vector<int> test;
  for(int i = 1; i <= n; i++) test.push_back(i);
  int cnt = 0;
  int a, b;
  do{
    cnt++;
    if(test == p) a = cnt;
    if(test == q) b = cnt;
  }while(next_permutation(test.begin(), test.end()));
  cout << abs(a-b) << endl;
  return 0;
}