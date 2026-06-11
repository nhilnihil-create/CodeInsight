#include <bits/stdc++.h>
using namespace std;


int main() {
  int n; cin >> n;
  int d[n];
  int D[n];
  for(int i = 0; i < n; i++){
    cin >> d[i];
    D[i] = d[i];
  }
  int sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i!=j){
        sum += d[i]*D[j];
      }
    }
  }
  if(sum%2==0) cout << sum/2 << endl;
  else cout << sum/2+1 << endl;
}