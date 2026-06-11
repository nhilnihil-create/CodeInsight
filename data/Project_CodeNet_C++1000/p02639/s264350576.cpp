#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main(){

  int x[5];
  int N=5;
  for (int i=0; i<N; i++)
    cin >> x[i];

  for (int i=0; i<N; i++)
    if (x[i] == 0) cout << i+1 << endl;

  return 0;
}