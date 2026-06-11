#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, n;
  cin >> N;
  n = N;
  vector<char> S(N);
  for (int i = 0; i < N; i++) {cin >> S.at(i);}
  for (int i = 0; i < N - 1; i++) {
    if (S.at(i) == S.at(i + 1)) {n--;}
  }
  cout << n << endl;
}