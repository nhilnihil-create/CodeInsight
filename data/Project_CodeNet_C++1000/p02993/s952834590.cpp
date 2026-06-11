#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  string n;
  cin >> n;
  rep(i,n.size()-1) {
    if (n.at(i) == n.at(i+1)) {
      cout << "Bad" << endl;
      return 0;
    }
  }
  cout << "Good" << endl;
}
