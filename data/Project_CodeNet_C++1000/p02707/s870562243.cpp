#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>vec(N,0);
  for(int i=0; i<N-1; i++){
    int S;
    cin >> S;
    vec[S-1]++;
  }
  for(int i=0; i<N; i++){
    cout << vec[i] << endl;
  }
}
