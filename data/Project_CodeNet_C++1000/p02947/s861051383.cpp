#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N,p=0;
  cin >> N;
  map<string, int> x;
  for(int i=0; i<N; i++){
    string S;
    cin >> S;
    sort(S.begin(),S.end());
    p += x[S];
    x[S]++;
  }
  cout << p << endl;
}
