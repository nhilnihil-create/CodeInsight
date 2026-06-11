#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string ans="No";
  for (int i=1; i<10; i++) {
    if (N%i!=0) {continue;}
    if ((N/i)/10==0) {
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
}