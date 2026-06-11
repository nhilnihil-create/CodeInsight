#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  
  for (int i=0 ; i<s.size() ; i++){
    s.at(i) += n;
    if (s.at(i) > 'Z')
      s.at(i) -= 26;
  }
  
  cout << s << endl;
}