#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> p(n);
  rep( i, 0, n ) cin >> p.at(i);

  int Ans = 0;

  rep( i, 0, n-2 ) {
    int MinVal = min( p.at(i), p.at(i+2) );
    int MaxVal = max( p.at(i), p.at(i+2) );
    if ( MinVal < p.at(i+1) && p.at(i+1) < MaxVal ) Ans++;
  }

  cout << Ans <<endl;
}
