#include<iostream>
using namespace std;

int main(){
  int k,n;
  cin >> k >> n;
  int d= n-k+1;
  for(int i=d;i<n+k;i++){
    cout << i << " ";
  }
  return 0;
}