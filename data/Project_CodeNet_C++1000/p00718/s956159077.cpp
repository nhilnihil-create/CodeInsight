#include <bits/stdc++.h>
using namespace std;

int to_int(string s) {
  int S = 0;  
  int num = 1;
  for ( int i = 0; i < (int)s.size(); i++ ) {
    if ( s[i] == 'm' ) {
      S += num*1000;
      num = 1;
    } else if ( s[i] == 'c' ) {
      S += num*100;
      num = 1;
    } else if ( s[i] == 'x' ) {
      S += num*10;
      num = 1;
    } else if ( s[i] == 'i' ) {
      S += num;
      num = 1;
    } else {
      num = s[i]-'0';      
    }
  }

  return S;
}

string to_str(int S) {  
  string s = "";
  int div = 1000;
  
  while ( S ) {
    int res = S/div;
    if ( res > 1 ) {
      s += (char)('0'+res);      
    }

    if ( res ) {
      if ( div == 1000 ) s += 'm';
      if ( div == 100  ) s += 'c';
      if ( div == 10   ) s += 'x';
      if ( div == 1    ) s += 'i';
    }
    
    S %= div;
    div /= 10;    
  }
  
  return s;  
}

int main() {
  int n;
  cin >> n;

  while ( n-- ) {
    string s, t;
    cin >> s >> t;

    int sum = to_int(s)+to_int(t);    
    cout << to_str(sum) << endl;    
  }
  
  return 0;
}

