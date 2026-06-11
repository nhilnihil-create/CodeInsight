#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  vector<string> s(N);
  vector<int> t(N);
  int total =0;

  for(int i=0;i<N;i++){
    cin >> s.at(i) >> t.at(i);
    total +=t.at(i);
  }

  string X;
  cin >> X;

  int second =total;
  for(int i=0;i<N;i++){
    second -= t.at(i);
    if(s.at(i) ==X){
      break;
    }

  }
  
  cout << second << endl;

}