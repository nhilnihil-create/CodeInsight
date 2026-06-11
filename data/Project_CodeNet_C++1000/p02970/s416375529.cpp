#include<bits/stdc++.h>
using namespace std;
int main(){
  double N,D; cin >> N >> D;
  double hanni = 2 * D + 1;
  cout << ceil(N / hanni) << endl;
}