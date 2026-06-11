#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  int N;
  cin >> N;
  string S,T,A;
  cin >> S >> T;
  A = S + T;
  rep(i,N){
    A.at(2*i) = S.at(i);
    A.at(2*i+1) = T.at(i);
  }
  cout << A << endl;
}