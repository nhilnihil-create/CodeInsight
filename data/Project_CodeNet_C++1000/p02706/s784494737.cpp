#include<iostream>
using namespace std;
#define pi 3.14159

int main(){
  int n,m,sum = 0;
  cin >> n >> m;
  int a[m];
  for(int i = 0 ; i < m;i++){
    cin >> a[i];
  }
  for(int i = 0 ; i < m;i++){
    sum += a[i];
  }
  if(n - sum >= 0){
    cout << n - sum << endl;
  }
  else{
    cout << -1 << endl;
  }
}