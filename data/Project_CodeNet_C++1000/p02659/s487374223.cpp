#include <bits/stdc++.h>
using namespace std; 

int main(){
  long long A;
  cin >> A;
  string S;
  cin >> S;
  S.erase(S.begin()+1);
  int B=stoi(S);
  cout << A*B/100 << endl;
}