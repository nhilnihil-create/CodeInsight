#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A=1000-N;
  while(true){
    if(A>=0){
      cout << A << endl;
      return 0;
    }
    A+=1000;
  }
}