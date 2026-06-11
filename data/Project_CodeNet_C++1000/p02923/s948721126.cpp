#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> h(n);  
  int count=0,max_reg=0;
  cin >> h[0];
  for(int i=1; i<n; i++){
    cin >> h[i];
    if(h[i]<=h[i-1]){
      count++;
      max_reg=max(count,max_reg);
    } else {
      count=0;
    }
  }
  cout << max_reg << endl;
  return 0;
}