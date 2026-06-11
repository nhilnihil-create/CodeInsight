#include <bits/stdc++.h>

using namespace std;

int main(){
  int X,i=0;
  cin >> X;
  int sum=X;
  for(;sum%360!=0;i++){
    sum=sum+X;
  }
  
  cout << i+1 << endl;
}