#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
   	cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  int counter = 0;
  
  for(int i = 0; i < n; i++){
   	for(int j = 0; j < i; j++){
      for(int k = 0; k < j; k++){
        if(a[i] == a[j]) continue;
        if(a[i] == a[k]) continue;
        if(a[j] == a[k]) continue;
        
        if(a[k] + a[j] > a[i]){
          counter++;
        }
      }
    }
  }
  
  cout << counter;
  return 0;
}