#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  for(int i=0;i<n;i++){//i番目のs文字
    for(int j=i;j<i+1;j++){//i番目のt文字
    cout << s.at(i) << t.at(j);
    }
  }
}
