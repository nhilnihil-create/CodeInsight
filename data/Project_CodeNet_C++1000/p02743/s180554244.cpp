#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int A, B, C;
  cin >> A >> B >> C;
  
  long long int test = C - A - B;

  if (test > 0 && test * test > 4 * A * B){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}