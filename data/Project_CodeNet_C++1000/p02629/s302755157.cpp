#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  
  int k = 26;
  
  string s = "";
  
  int i = 0;
  while(n){
    n--;
    s  += (char)('a' + n % 26);
    n /= 26;
    
  }
  
  reverse(s.begin(), s.end());
  
  cout << s << endl;
    
  

}