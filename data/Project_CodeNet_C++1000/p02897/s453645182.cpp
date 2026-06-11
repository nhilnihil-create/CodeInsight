#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  
  if(N%2==0){
    int a = N/2;
    cout << (float)a/N << endl;
  }else{
    int a = (N+1)/2;
    cout << (float)a/N << endl;
  }
  
  return 0;
}
