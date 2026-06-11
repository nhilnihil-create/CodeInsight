#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  if (N % 2 == 1)
  {
    N = N / 2 + 1;
  }
  else
  {
    N /= 2;
  }
  cout << N << endl;
}