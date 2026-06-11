#include <bits/stdc++.h>
//#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  
  int N;
  string S="";
  string T="";

  cin >> N >> S;
  if(N%2 == 0){
    for (int i=0;i<N/2;++i){
      T += S[i];
    }
    if(S == (T+T)){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }

  }else{
    cout << "No" << endl;
  }

  return 0;
}