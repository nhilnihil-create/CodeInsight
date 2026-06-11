#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> a(3);
  for(int i=0; i<3; i++){
    cin >> a[i];
  }
 
  int sum=0;
  for(int j=0; j<3; j++){
    sum = sum + a[j];
  }
  
  if(sum <= 21){
    cout << "win" << endl;
  }
  else{
    cout << "bust" << endl;
  }
  
}
