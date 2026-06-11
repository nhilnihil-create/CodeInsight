#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N, D; cin >> N >> D;

  int Ans = 0;
  int CoverRange = D*2+1;

  while( N>0 ) {
    N -= CoverRange;
    Ans++;
  }

  cout << Ans <<endl;
}
