#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  string s;
  cin >> k >> s;
  if(s.size() > k)cout << s.substr(0,k)<< "..." <<endl;
  if(s.size() <= k)cout << s <<endl;
}