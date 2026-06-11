#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  int x = 0;
  while(A>0){
    A -= B;
    x++;
  }
  cout << x << endl;
}