#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D,K;
  cin >> A >> B >> C >> D >> K;
  int S,T;
  S=60*A+B,T=60*C+D;
  cout << T-S-K << endl;
}
  