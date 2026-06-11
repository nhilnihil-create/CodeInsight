#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  
  int c = 0;
  rep(i,n-1) if(s[i] == s[i+1]) c++;
  
  cout << min(c + 2 * k, n - 1) << endl;
  return 0;
}