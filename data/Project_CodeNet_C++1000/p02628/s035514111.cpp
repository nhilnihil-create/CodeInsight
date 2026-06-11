#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, K, answer;
  answer = 0;
  cin >> N >> K;
  vector<int> p(N);
  for(int i = 0; i < N; i++){
    cin >> p[i];
  }
  
  sort(p.begin() , p.end() );
  
  for(int i = 0; i < K; i++){
    answer += p[i];
  }

  cout << answer << endl;
}
