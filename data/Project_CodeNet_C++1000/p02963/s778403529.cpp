#include <bits/stdc++.h>
using namespace std;
int main(){
  long long S;
  cin >> S;
  cout << 0 << ' ' << 0 << ' ' << 1 << ' ' << 1000000000 << ' ' << (S + 1000000000 - 1) / 1000000000 << ' ' << (1000000000 - S % 1000000000) % 1000000000 << endl;
}