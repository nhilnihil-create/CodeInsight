#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s, t, m;
  cin >> n >> s >> t;

  for(int i = 0; i<s.size() * 2; i++){
    if(i%2 == 0)
      m += s.at(i/2);
    else
      m += t.at(i/2);
  }
  cout << m << endl;
}