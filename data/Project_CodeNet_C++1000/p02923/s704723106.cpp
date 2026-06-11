#include <iostream>
using namespace std; 
int main(){
  
  int n;
  cin >> n;
  long long  arr[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  int maxi = 0,cnt = 0;
  for(int i = 0; i < n - 1; i++){
    if(arr[i] >= arr[i + 1]){
      cnt += 1;
      maxi = max(maxi,cnt);
      continue;
    }
    cnt = 0;
  }
  cout << maxi;
    
}