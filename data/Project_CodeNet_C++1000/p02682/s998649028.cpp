#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  int sum = 0;
  if(K > A){
    sum += A;
    K -= A;
  } else{
    sum = K;
    K = 0;
  }
  if(K > 0){
    if(K > B){
      K -= B;
    } else{
      K = 0;
    }
  }
  if(K > 0){
    sum -= K;
  }
  cout << sum <<endl;
}
