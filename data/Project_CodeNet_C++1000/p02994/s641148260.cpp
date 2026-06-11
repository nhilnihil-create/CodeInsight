#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N, L; cin >> N >> L;

  vector<int> Aji(N);
  int Sum = 0;
  int AjiMin = INT_MAX;
  int EatApple = 0;
  rep( i, 0, N ) {
    if ( i==0 ) Aji.at(i) = L;
    else Aji.at(i) += Aji.at( i-1 ) + 1;
    Sum += Aji.at(i);
    int AbsVal = abs( Aji.at(i) );
    if ( AbsVal < AjiMin ) {
      AjiMin = AbsVal;
      EatApple = Aji.at(i);
    }
  }
  cout << Sum - EatApple <<endl;
}
