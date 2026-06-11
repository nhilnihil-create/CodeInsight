#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B; cin >> A >> B; int ans = -1;
  vector<int> kouho(1251,0);
  int i =1;
  while (i <=1250) {
    int kouhoA = i * 0.08; int kouhoB = i * 0.1;
    if (kouhoA == A) kouho.at(i)++; 
    if (kouhoB == B) kouho.at(i)++; 
    i++;
  }
 
  for (int i =1; i<=1250; i++) {
    if (kouho.at(i) == 2) {
      ans = i; break;
    }
  }
  cout << ans << endl;
}