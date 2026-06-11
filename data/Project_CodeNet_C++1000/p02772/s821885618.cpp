#include<bits/stdc++.h>
using namespace std;

int main (void){
  int a[110];
  int n;
  cin >> n;

  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  for(int i = 0;i < n;i++){
    if(a[i] % 2 == 0){
      if(a[i] % 3 != 0 && a[i] % 5 != 0){
        cout << "DENIED\n";
        return 0;
      }
    }
  }
  cout << "APPROVED\n";
  return 0;

}