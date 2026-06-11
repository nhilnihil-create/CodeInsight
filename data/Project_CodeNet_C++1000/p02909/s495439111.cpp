#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    vector<string> a = {"Sunny", "Cloudy", "Rainy"};
    string s;
    cin >> s;
    rep(i,2){
      if(s == a.at(i)) cout << a.at(i+1) << endl;
    }
    if(s== a.at(2)) cout << a.at(0) << endl;
    
  }
