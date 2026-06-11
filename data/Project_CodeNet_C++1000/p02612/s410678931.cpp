#include<bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N;
  M=0;
  if(N%1000!=0) {
    M=1000-N%1000;
  }
  cout << M << endl;
}