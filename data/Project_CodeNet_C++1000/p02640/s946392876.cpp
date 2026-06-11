#include<bits/stdc++.h>
using namespace std;

int main(){
  int t,k;
  cin >> t >> k;
  int s=4*t;
  while(s>k&&s>2*t)
    s-=2;
  cout << (s==k?"Yes":"No") << endl;
  return 0;
}