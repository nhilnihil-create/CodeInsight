#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin >> n;
  int d[n];
  rep(i,n){cin >> d[i];}
  
  int sum = 0;
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      sum += d[i]*d[j];
    }
  }
  
  cout << sum << endl;
}