#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  
  long long x = n;
  string s = "";
  char c;
  
  while(n>26){
    x = n % 26;
    if(x==0){
      c = 'z';
      n -= 26;
    }
    else
      c = 'a' + x - 1;
    s = c + s;
    n /= 26;
  }
  

  c = 'a' + n - 1;
  s = c + s;
  
  
  cout << s << endl;
}
