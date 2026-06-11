#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int N, X, Y;
  cin >> N >> X >> Y;
  
  vector<int> ans(N + 1, 0);
  for (int i = 1; i < N; i++){
    for (int j = i + 1; j < N + 1; j++){
      int kouho1 = j - i;
      int kouho2 = abs(X - i) + 1 + abs(Y - j);
      ans.at(min(kouho1, kouho2))++;
    }
  }
  
  for (int i = 1; i < N; i++){
    cout << ans.at(i) << endl;
  }
}