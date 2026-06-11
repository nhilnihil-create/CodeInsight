#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG



int main() {
  ll A, B, ans;
  cin >> A >> B;


  ll x, y;
  for(ll i=0; i <= 1009 ; i++){
    x = i * 0.08;
    y = i * 0.1;
    if (x == A && y == B){
      cout << i << endl;
      return 0;
    }

  } 

  cout << "-1" << endl;

  return 0;
}
