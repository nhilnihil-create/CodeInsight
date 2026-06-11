#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  int c = 0;
  int sum = 0;
  int i;
  float vote;
  
  cin >> n >> m;
  int a[n];
  for(i = 0; i < n; i++){
  	cin >> a[i];
  }
  for(i = 0; i < n; i++){
  	sum += a[i];
  }
  for(i = 0; i < n; i++){
  	if(a[i] * (4 * m) >= sum){
      c++;
    }
  }
  if(c >= m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl; 
  return 0;
}