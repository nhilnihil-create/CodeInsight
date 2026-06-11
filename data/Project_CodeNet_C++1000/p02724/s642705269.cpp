#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;

int main(){
  int a;
  cin >> a;
  int b, c;
  b = a/500;
  a = a-b*500;
  c = a/5;
  cout << b*1000 + c*5 << endl;
}