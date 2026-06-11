#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <math.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> data(n, vector<int>(d));
  rep(i, n) {
    rep(j, d) {
      int x;
      cin >> x;
      data.at(i).at(j) = x;
    }
  }
  int count = 0;
  rep(i, n) {
    for (int j = i+1; j < n; j++) {
      double dis = 0;
      rep(k, d) {
        dis += (data.at(i).at(k) - data.at(j).at(k))*(data.at(i).at(k) - data.at(j).at(k));
      }
      //cout << dis << endl;
      double disru = sqrt(dis);
      double syo;
      syo = disru - (int)disru;
      //cout << (int)disru << endl;
        
      if (syo == 0) {
        count++;
      }
    }
  }
  cout << count << endl;
}
        
