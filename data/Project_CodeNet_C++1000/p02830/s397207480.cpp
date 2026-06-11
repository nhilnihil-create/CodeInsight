#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  string T;
  cin >> T;
  for (int i=0;i<N;i++){
    cout << S.at(i) <<T.at(i);
    if(i==N-1){
      cout << endl;
    }
  }
}