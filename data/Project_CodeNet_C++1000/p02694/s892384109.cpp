#include <bits/stdc++.h>
using namespace std;

int main() {
  long long  N,X=0;
  long long Y=100;
  cin >> N;
  while (Y<N){
    X++;
    Y += Y/100;
  }
  cout << X << endl;
}
