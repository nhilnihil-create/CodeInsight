#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  string n;
  cin >> n;
  bool a = false;
  rep(i,n.size()){
    if(n.at(i) == '7'){
      cout << "Yes" << endl;
      a = true;
      break;
    }else{
      continue;
    }
  }
  if(a == false){
    cout << "No" << endl;
  }

}