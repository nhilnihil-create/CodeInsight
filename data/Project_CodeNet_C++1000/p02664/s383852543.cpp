#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  string S;
  cin >> S;

  for(int i = 0;i < S.size();i++) {
    if(S[i] == '?') S[i] = 'D';
  }

  cout << S << endl;
  
  

}
