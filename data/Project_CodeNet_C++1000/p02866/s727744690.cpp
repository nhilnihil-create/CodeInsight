#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int N;
  cin >> N;
  
  vector<int> Dnum(N, 0), D(N);
  for (int i = 0; i < N; i++){
    int num;
    cin >> num;
    
    D.at(i) = num;
    Dnum.at(num)++;
  }
  
  if (Dnum.at(0) != 1 || D.at(0) != 0){
    cout << "0" << endl;
    exit(0);
  }
  
  ll ans = 1;
  for (int i = 0; i < N; i++){
    if (D.at(i) == 0){
      continue;
    }
    ans *= Dnum.at(D.at(i) - 1);
    ans %= 998244353;
  }

  cout << ans << endl;
}