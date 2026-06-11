#include<bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  string S,T="111";
  cin >> N >> S;
  T.at(0)=S.at(0);
  T.at(1)=S.at(2);
  T.at(2)=S.at(3);
  int A=stoi(T);
  cout << N*A/100 << endl;
}