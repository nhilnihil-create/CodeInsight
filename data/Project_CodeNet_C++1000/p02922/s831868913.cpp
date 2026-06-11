#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  int i;
  int count = 1;
  for(i = 0; count < B; i++){
    count += A - 1;
  }
  cout << i << endl;
}