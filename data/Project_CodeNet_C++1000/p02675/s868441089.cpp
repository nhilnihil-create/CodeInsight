#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int M = N % 10;
  
  if( M == 2 || M  == 4 || M == 5 || M ==  7  || M == 9){
    cout << "hon" << endl;
  }
  
  else if ( M == 0 || M == 1 || M == 6 || M == 8 ){
    cout << "pon" << endl;
  }
  
  else if ( M == 3 ) {
    cout << "bon" << endl;
  }
  
  
}