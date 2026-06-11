#include<iostream>
#include<string>
using namespace std;
int main(){
  int n , m;
  n = 9;
  int a[n + 1], b[m];
  for(int i = 1; i < 10; i++){
    cin >> a[i];
  }
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }
  for(int i = 1; i < 10; i++){
    for(int j = 0; j < m; j++){
      if(a[i] == b[j]){
        a[i] = -1;
        break;
      }
    }
  }
  if(a[5] == -1){
    if(a[1] == -1 && a[9] == -1){
      cout << "Yes\n";
      return 0;
    }
    if(a[2] == -1 && a[8] == -1){
      cout << "Yes\n";
      return 0;
    }
    if(a[3] == -1 && a[7] == -1){
      cout << "Yes\n";
      return 0;
    }
    if(a[4] == -1 && a[6] == -1){
      cout << "Yes\n";
      return 0;
    }
  }
  if(a[1] == -1 && a[2] == -1 && a[3] == -1){
      cout << "Yes\n";
      return 0;
  }
  if(a[7] == -1 && a[8] == -1 && a[9] == -1){
      cout << "Yes\n";
      return 0;
  }
  if(a[1] == -1 && a[4] == -1 && a[7] == -1){
      cout << "Yes\n";
      return 0;
  }
  if(a[3] == -1 && a[6] == -1 && a[9] == -1){
      cout << "Yes\n";
      return 0;
  }
  cout << "No\n";
}