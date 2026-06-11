#include<bits/stdc++.h>
using namespace std;

int main() {
  int s; cin >> s;
  bool ans=false;
  for(int i=0; i<3; i++) {
    int a=s/10;
    if(s%10 == a%10) ans=true;
    else s/=10;
  }
  if(ans) cout << "Bad" << endl;
  else cout << "Good" << endl;
}