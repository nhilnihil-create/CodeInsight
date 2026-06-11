#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; 
  cin >> n;
  
  vector<int> p(n);
  for(int i=0; i<n; i++){
    cin >> p[i];
  }
 
  vector<int> q(n);
  for(int j=0; j<n; j++){
    q[j] = j+1;
  }
  
  int sum=0;
  int num=0;
  for(int k=0; k<n; k++){
    sum += p[k] - q[k];
    if(p[k] != q[k]){
      num++;
    }
  }
  
  if(sum==0 && num==2){
    cout << "YES" << endl;
  }
  else if(sum==0 && num==0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
  
  
}
