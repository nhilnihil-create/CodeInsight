#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> x(2);
  cin >> x.at(0) >> x.at(1);
  int ans=0;
  for (int i:x){
    if (i==1) ans+=300000;
    else if (i==2) ans+=200000;
    else if (i==3) ans+=100000;
  }
  if (ans==600000) ans+=400000;
  cout << ans << endl;
}