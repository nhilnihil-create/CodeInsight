#include<iostream>
#include<string>
using namespace std;
int main(){
  int n, m, k = 0;
  cin >> n >> m;
  for(int i = 1; i < n; i++){
    k = k + i;
  }
  for(int j = 1; j < m; j++){
    k = k + j;
  }
  cout << k << "\n";
}