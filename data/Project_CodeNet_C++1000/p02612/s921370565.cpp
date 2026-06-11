#include <iostream>
#include <vector>
#define rep(i, n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  
  cout << ((N - 1) / 1000 + 1) * 1000 - N;
}

