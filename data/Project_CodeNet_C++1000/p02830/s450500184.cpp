#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int main() {
  int n;
  string s,t;
  cin >> n >> s >> t;
  string u(2*n,'0');
  for(int i = 0; i < 2*n; i++){
    if(i%2 == 0){
      u.at(i) = s.at(i/2);
    }else{
      u.at(i) = t.at(i/2);
    }
  }
  cout << u << endl;
  
  }
