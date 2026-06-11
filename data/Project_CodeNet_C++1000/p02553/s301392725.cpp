#include <bits/stdc++.h>
using namespace std;

int main(){
  long a, b, c, d;
  long e;
  cin >> a >> b >> c >> d;
  vector<long> x = {a*c, a*d, b*c, b*d};
  e = a * c;
  for(int i = 0; i < 4; i++){
    if(e < x.at(i)){
      e = x.at(i);
    }
  }
  cout << e << endl;
}