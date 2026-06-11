#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int Y=0;
  int X=0;
  int goukei=0;
  cin >> N;
  vector<int>vec(N);
  for (int L=0; L<N; L++){
    cin >>vec.at(L);
  }
  for (X=0; X<N; X++){
    for (Y=0; Y<N; Y++){
      goukei+=vec.at(X)*vec.at(Y);
    }
    goukei-=vec.at(X)*vec.at(X);
  }
  cout << goukei/2 << endl;
}