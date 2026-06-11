#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,N;
  cin >> X >> N;
  int minP = 0;
  vector<bool> ped(100);
  for(int i = 0; i < N; i++){
    int p;
    cin >> p;
    ped[p-1] = true;
  }
  for(int i = -1; i < 101; i++){
    if(i >= 0){
      if(ped[i]) continue;
    }
    if(abs(minP-X) > abs(i+1-X)) minP = i+1;
  }
  cout << minP << endl;
}