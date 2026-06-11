#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++){
    cin >> p[i];
  }
  
  int ans = 0;
  for (int i = 1; i < N - 1; i++){
    if (p[i - 1] < p[i] && p[i] < p[i + 1]){
      ans++;
    }
    else if (p[i - 1] > p[i] && p[i] > p[i + 1]){
      ans++;
    }
  }
  cout << ans << endl;
}
