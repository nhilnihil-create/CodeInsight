#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> a(N);
  long long B = 0;
  for(int i = 0; i < N; i++) cin >> a[i], B ^= a[i];
  for(int i = 0; i < N; i++) cout << (a[i]^B) << " ";
  cout << "" << endl;
}
