#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<string> ans = {"pon","pon","hon","bon","hon","hon","pon","hon","pon","hon"};
  int n; cin >> n;
  cout << ans.at(n%10) << endl;
}