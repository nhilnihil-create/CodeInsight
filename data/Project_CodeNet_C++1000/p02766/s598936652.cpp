#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, K;
  cin >> N >> K;

  int digit = 0;
  while(N / K != 0){
    N /= K;
    digit += 1;
  }

  cout << digit + 1 << endl;
}