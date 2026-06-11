#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n=s.size();
  if ( n&1 ) {
    puts("No");
    return 0;
  }
  for ( int i=0; i<n; i+=2 ) {
    if ( s[i]!='h'||s[i+1]!='i' ) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}