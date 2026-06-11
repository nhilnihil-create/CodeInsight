#include <bits/stdc++.h>
using namespace std;

int main() {
  int K,N;
  cin >> K >> N;
  vector<int> pl(N);
  for(int i=0;i<N;i++)
    cin >> pl.at(i) ;
  vector<int> d(N);
  d.at(0) = pl.at(N-1) - pl.at(0);
  for(int i=1;i<N;i++)
    d.at(i) = K - pl.at(i) + pl.at(i-1);
  sort( d.begin(),d.end() );
  cout << d.at(0) << endl;
  
}
