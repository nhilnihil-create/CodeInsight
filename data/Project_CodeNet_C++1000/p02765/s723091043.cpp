#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,R;
  cin>>N>>R;
  int IR;
  if(N >= 10) IR = R;
  else IR = R+100*(10-N);
  cout<<IR<<endl;
}