#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  int a = (N+M)*(N+M-1);
  int b = a/2;
  
  int c = N*M;
  
  cout << b-c << endl;
  
}