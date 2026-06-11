#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG


int main() {
  string S;
  cin >> S;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));
  if (S.at(2)==S.at(3) && S.at(4)==S.at(5)){
  cout << "Yes" << endl;
  return 0;  
  }
  cout << "No" << endl;
  return 0;
}
