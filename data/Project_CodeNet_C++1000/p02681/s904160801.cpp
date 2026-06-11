#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  string s,t;
  cin >> s >> t;
  
  int count = 0;
  rep(i,s.size()){
    if(t.at(i) == s.at(i)){
      count++;
    }
  }
  if(count == s.size()){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }


}
