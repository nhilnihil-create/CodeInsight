#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, M;
  cin >> N >> M;

  vector<int> vec(N);

  int sum = 0;  
  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  
  int pop = 0;
  for (int i = 0; i < N; i++){
    if (vec.at(i) * 4 * M >= sum) pop += 1;
  }

  cout << (pop >= M ? "Yes" : "No") << endl;
}