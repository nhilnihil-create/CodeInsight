#include <bits/stdc++.h>
using namespace std;

int main() {
  int H1,M1,H2,M2,K,ans=0,minute=0; cin >> H1 >> M1 >> H2 >> M2 >> K;
  cout << 60*(H2-H1) + (M2-M1) -K << endl;
}