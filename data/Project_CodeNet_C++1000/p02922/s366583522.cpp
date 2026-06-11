#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  int count = 1;
  int i = 0;
  while(count < B) {
    count = count + A - 1;
    i++;
  }
  cout << i << endl;
}