#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG




int main() {
  ll a, b;
  cin >> a >> b;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));
  if (a <= b){
    for(ll i=0; i< b;i++){
      cout << a;
    }
    cout << endl;
  }else{
    for(ll i=0; i< a;i++){
      cout << b;
    }
    cout << endl;
  }
  
  return 0;
}
