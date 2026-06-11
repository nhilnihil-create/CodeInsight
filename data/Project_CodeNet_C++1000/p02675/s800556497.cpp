#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N, N_kazu;
  cin >> N;
  N_kazu = N % 10;
  switch(N_kazu){
  case 0:
  case 1:
    cout << "pon" << endl;
    break;
  case 2:
    cout << "hon" << endl;
    break;
  case 3:
    cout << "bon" << endl;
    break;
  case 4:
  case 5:
    cout << "hon" << endl;
    break;
  case 6:
    cout << "pon" << endl;
    break;
  case 7:
    cout << "hon" << endl;
    break;
  case 8:
    cout << "pon" << endl;
    break;
  case 9:
    cout << "hon" << endl;
    break;
  }
  return 0;
}