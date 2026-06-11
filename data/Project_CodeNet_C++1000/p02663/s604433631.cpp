#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < (int)(n); i++)

int main(){
  int H1, M1, H2, M2, K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  
  int min;
  min = (H2*60+M2) - (H1*60+M1);
  
  cout << min-K << endl;
}

