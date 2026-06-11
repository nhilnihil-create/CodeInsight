#include <bits/stdc++.h>
using namespace std; 

int main(){
  int sum=0;
  for(int i=0;i<5;i++){
    int X;
    cin >> X;
    sum+=X;
  }
  cout << 15-sum << endl;
}