#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,M,G,N,K;
  cin >> H >> M >> G >> N >> K;
  cout << (G*60+N)-(H*60+M)-K << endl;
}