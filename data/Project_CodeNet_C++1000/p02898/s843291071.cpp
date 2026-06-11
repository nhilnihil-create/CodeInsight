#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,X=0;
  cin >> N >> K;
  for(int i=0; i<N; i++){
    int a;
    cin >> a;
    if(a>=K){
      X++;
    }
  }
  cout << X << endl;
}
