#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  int N;
  cin >> N;
  string c;
  cin >> c;
  int red = 0;
  for(int i = 0; i < N; i++) {
    if(c[i] == 'R') red++;
  }
  if(red == N) { cout << 0; return 0; }
  int a = 0;
  for(int i = 0; i < red; i++) {
    if(c[i] == 'R') a++;
  }

  cout << red - a;
  return 0;
}