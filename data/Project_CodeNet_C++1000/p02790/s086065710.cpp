#include <bits/stdc++.h>
using namespace std;

void solve(int x, int y){
  for(int i=0; i<y; i++){
    string s = to_string(x);
    cout<<s;
  }
}

int main() {
  int a,b;
  cin>>a>>b;
  if(a<=b){
    solve(a,b);
  }
  else solve(b,a);
}