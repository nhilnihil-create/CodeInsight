#include<iostream>
using namespace std;


int main(){
  int n, m;
  cin >> n >> m;
  int e,o;

  e = n * (n - 1) / 2;
  o = m * (m - 1) / 2;

  cout << e + o << endl;
  return 0;

}
