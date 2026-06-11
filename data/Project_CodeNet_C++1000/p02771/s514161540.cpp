#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG




int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));

  if(A==B && A==C ){
    cout << "No" << endl;
    return 0;
  }
  if(A!=B && A!=C && B!=C){
    cout << "No" << endl;
    return 0;
  }
  
  cout << "Yes" << endl;
  return 0;
}
