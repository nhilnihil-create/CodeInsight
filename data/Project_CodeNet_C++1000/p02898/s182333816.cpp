#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, k;
  cin >> n >> k;
  
  vector<int> h(n);
  for(int i=0; i<n; i++){
    cin >> h[i];
  }
 
  int num=0;
  for(int j=0; j<n; j++){
    if(h[j] >= k){
      num++;
    }
  }
  
  cout << num << endl;
  
  
}