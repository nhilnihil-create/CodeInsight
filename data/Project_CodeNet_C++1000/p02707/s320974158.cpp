#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,A;
  cin>>N;
  
  vector<int> vec(N);
  
  rep(i,N-1){cin >> A;
          vec.at(A-1)++;}
  rep(i,N){cout<<vec.at(i)<<endl;}
}