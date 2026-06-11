#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string S; cin >> S;
  
  int count =0;
  for (int i =0; i<1000; i++) {
    int a,b,c;
    a = i / 100; 
    b = (i - a * 100) / 10;
    c = i % 10;
    int count3 =0;
    for (int j =0; j<N; j++) {
      if (S.at(j) - '0' == a && count3 == 0) {
        count3++;
      } else if (S.at(j) - '0' == b && count3 == 1) {
        count3++;
      } else if (S.at(j) - '0' == c && count3 == 2) {
        count3++;
      }
      if (count3 == 3) break;
    }
    if (count3 == 3) {
      count++;
    }
  }
  cout << count << endl;  
}
