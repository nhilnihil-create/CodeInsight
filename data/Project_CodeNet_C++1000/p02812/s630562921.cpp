#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
 
int main() {
  int n;
  string s;
  cin >> n >> s;
  
  int count = 0;
  
  for (int i = 0; i < n - 2;){
    if (s.substr(i, 3) == "ABC") {
      count++;
      i += 3;
    } else {
      i++;
    }
  }
  
  cout << count << endl;
}
