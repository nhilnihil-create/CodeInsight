#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  string t = s;
  int n = s.size();
  rep(i,n){
    t[i] = 'x';
  }
  cout << t << endl;
}
