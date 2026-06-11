#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;

int main() {
  long long  A, b;
  string B;
  char c;
  cin >> A;
  
  rep(i, 4){
    cin >> c;
    if(c !='.') B += c;
  }
  b = stoll(B);
  
  cout << (A*b)/100 << endl;
  return 0;
}