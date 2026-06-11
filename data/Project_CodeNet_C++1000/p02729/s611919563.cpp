#include <bits/stdc++.h>
using namespace std;


int main() {
  int n,m;
  
  cin >> n >> m;
  
  int sum1=0,sum2=0;
  
  for(int i=0; i<n; i++){
    sum1+=i;
  }
  
  for(int i=0; i<m; i++){
    sum2+=i;
  }
  
  cout << sum1+sum2;
  
  
  
}