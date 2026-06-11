#include <bits/stdc++.h>
using namespace std;

int main(){
  int H1,M1,H2,M2,K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  int S=60*H1+M1,T=60*H2+M2;
  cout << T-S-K << endl;
}