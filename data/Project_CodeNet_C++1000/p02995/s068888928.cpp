#include <bits/stdc++.h>
using namespace std;
 
int main() {
long long A,B,C,D;
  cin >> A >> B >> C >> D;
  long long c = C;
  long long d = D;
  for(int a = 0;c != d;a++){
   if(c < d)d %= c;
    if(d == 0){
     d = c;
      break;
    }
    if(d < c)c %= d;
    if(c == 0){
     c = d;
      
      break;
    }
  }
  
  long long a = (A-1) / C + (A-1) / D - (A-1) / (C * D / c);
  long long b = B / C + B / D - B / (C * D / c);
  cout << (B - A + 1) - (b - a) << endl;
}