#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, count;
  cin >> N;
  string S;
  cin >> S;
  count =0;
  for (int i=0; i<N-2 ; i++){
    if(S.at(i)=='A'){
      if(S.at(i+1)=='B'){
        if(S.at(i+2)=='C'){
          count++;
        }
      }
    }
  }
  cout << count << endl;
}