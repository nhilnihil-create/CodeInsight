#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int N, K;
  cin >> N >> K;
  
  vector<int> A(N), num(2001, 0);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
    num.at(A.at(i))++;
  }
  
  long long int base = 0;
  for (int i = 0; i < N - 1; i++){
    for (int j = i + 1; j < N; j++){
      if (A.at(i) > A.at(j)){
        base++;
      }
    }
  }
  
  long long int ruiseki = 0, ans = 0;
  ans = base * K;
  for (int i = 1; i <= 2000; i++){
    ans += num.at(i) * ruiseki * ((K * (K - 1) / 2) % 1000000007);
    ans %= 1000000007;
    ruiseki += num.at(i);
  }

  cout << ans << endl;
    
}