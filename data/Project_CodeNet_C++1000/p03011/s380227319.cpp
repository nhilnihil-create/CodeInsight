#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int P,Q,R;
  cin>>P>>Q>>R;
  vector<int>F(3);
  F[0]=P;
  F[1]=Q;
  F[2]=R;
  sort(F.begin(),F.end());
  cout<<F[0]+F[1]<<endl;
}