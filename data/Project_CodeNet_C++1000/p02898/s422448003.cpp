#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  
  int Ans=0;
  int h;
  
  for(int i=0;i<N;i++){
    cin >> h;
    if(h >= K) Ans++;
  }
  
  cout << Ans << endl;
}
