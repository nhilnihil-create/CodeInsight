#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string S;
  cin >> N >> S;
  int count = 0;
  for (int i = 0; i < N - 2; i++) {
    string abc = "";
    abc += S[i];
    abc += S[i + 1];
    abc += S[i + 2];
    if (abc == "ABC") {
      count += 1;
    }
  } 
  cout << count << endl;
}