#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;


int main() {
  int n;
  cin >> n;
 
 
  int q = n % 1000;
  
  cout << (1000 - q) % 1000 << endl;
  
}