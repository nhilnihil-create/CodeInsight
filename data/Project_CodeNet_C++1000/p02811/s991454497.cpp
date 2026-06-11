#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(s,t) for (int s = 0; s < t; ++s);
using ll = long long;


int main() {
  int k,x;

  cin >> k >> x;

  if (500 * k >= x){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
} 