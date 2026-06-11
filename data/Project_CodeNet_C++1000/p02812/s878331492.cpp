#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  string t = "ABC";
  vector<int> result; 
  int size = t.size();
  int f = s.find(t);
  while (f != ::string::npos) {
    result.push_back(f);
    f = s.find(t,f+size);
  }
  cout << result.size() << endl;
}