#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int ans;
  ans = 0;
  for (int i = 1; i < 10; i++) {
    
    for (int s = 1; s < 10; s++) {
      int is;
      is = i * s;
      if (N == is) {
        ans = is;
      }
    }
  }
  if (ans != 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
}