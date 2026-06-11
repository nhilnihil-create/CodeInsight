#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M; cin >> N >>M;
  for(int i = 0; i < M; i++){
    int a; cin >> a;
    N -= a;
    if(N < 0){
      cout << -1 <<endl;
      return 0;
    }
  }
  cout << N << endl;
}