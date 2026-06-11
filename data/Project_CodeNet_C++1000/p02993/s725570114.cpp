#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;

int main() {
  string s;
  cin >> s;
  rep(i,3){
    if(s[i]==s[i+1]){cout << "Bad" << endl; return 0;}
  }
  cout << "Good" << endl;
}