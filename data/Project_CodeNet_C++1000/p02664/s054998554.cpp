#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  string t;
  cin >> t;
  int s=t.size();
  for(int i=0;i<s;i++){
    if(t.at(i)=='?')
    t.at(i)='D';
  }
  cout << t << endl;
}
