#include <bits/stdc++.h>
using namespace std;
#define rep(i,A) for(int i = 0;i < A;i++)

int main() {
  string S;
  cin >> S;
  int count = 0;
  rep(i,3){
    if(S[i] == 'R'){
      count++;
    }
  }
    if(count != 2){
      cout << count << endl;
    }
    else{
      if(S[1] == 'R'){
        cout << 2 << endl;
      }
else{
  cout << 1 << endl;
}
    }

  }
