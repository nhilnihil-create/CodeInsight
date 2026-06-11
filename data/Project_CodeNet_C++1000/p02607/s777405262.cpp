#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >> N;
  B=0;
  
  for(int i=0;i<N;i++){
    cin >> A;
    if((i+1)%2==1&&A%2==1){B++;}
  }
  cout << B << endl;
}