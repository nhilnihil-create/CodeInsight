#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int s;
  cin >> s;
  long long int x1, x2, x3, y1, y2, y3;
  x1 = 0;
  y1 = 0;
  x2 = 1000000000;
  y2 = 1;
  y3 = s/(1000000000);
  if(s != y3*1000000000){
    y3++;
  }
  x3 = y3*(1000000000)-s;
  string x1s, x2s, x3s, y1s, y2s, y3s;
  x1s = to_string(x1);
  x2s = to_string(x2);
  x3s = to_string(x3);
  y1s = to_string(y1);
  y2s = to_string(y2);
  y3s = to_string(y3);
  string s_ans = x1s + ' '+ y1s + ' '+  x2s +' '+ y2s+' ' + x3s+' ' + y3s;
  cout << s_ans << endl;
  //cout << x2*y3-x3*y2 << endl;
  //cout << y3*1000000000 << endl;
}
