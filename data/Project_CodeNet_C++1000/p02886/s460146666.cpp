#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){    
  int N,a;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++){
    cin >> a;
    vec[i] = a;
  }
  ll Ans = 0;
  for(int i = 0; i < N-1; i++){
    for(int j = i+1; j < N; j++){
      Ans += vec[i] * vec[j];
    }
  }
  cout << Ans << endl;
}
