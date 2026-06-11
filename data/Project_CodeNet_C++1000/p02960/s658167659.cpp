#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n = s.size();
  const int MOD = 1000000007;

  int table[n][13];
  for(int i=0; i<n; i++) {
    for(int j=0; j<13; j++) {
      table[i][j] = 0;
    }
  }
  if(s[0]=='?') {
    for(int i=0; i<10; i++) table[0][i] = 1;
  }
  else {
    table[0][(int)(s[0]) -48] = 1;
  }

  const int trans[13] = {0,10,7,4,1,11,8,5,2,12,9,6,3};

  for(int i=1; i<n; i++) {
    // cout<<(int)(s[i])<<endl;
    if(s[i]=='?') {
      for(int add=0; add<10; add++) {
        for(int j=0; j<13; j++) {
          table[i][(trans[j]+add)%13] += table[i-1][j];
          table[i][(trans[j]+add)%13] = table[i][(trans[j]+add)%13]%MOD;
        }
      }
    }
    else {
      int add = (int)(s[i]) -48;
      for(int j=0; j<13; j++) {
        table[i][(trans[j]+add)%13] = table[i-1][j];
      }
    }
  }

  cout<<table[n-1][5]<<endl;


  return 0;
}