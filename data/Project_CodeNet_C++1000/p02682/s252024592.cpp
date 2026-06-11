#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,B,C,K,X=0;
  cin >> A >> B >> C >> K;
  for(long long i=0;i<A; i++){
    X++;
    K--;
    if(K == 0){
      cout << X << endl;
      return 0;
    }
  }
  for(long long i=0;i<B; i++){
    K--;
    if(K == 0){
      cout << X << endl;
      return 0;
    }
  }
  for(long long i=0; i<C; i++){
    X--;
    K--;
    if(K == 0){
      cout << X << endl;
      return 0;
    }
  }
  cout << X << endl;
}
