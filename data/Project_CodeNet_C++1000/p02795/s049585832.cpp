#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W,N;
  cin >> H>>W>>N;
  int num;
  if(N%max(H,W)!=0){
    num=N/max(H,W)+1;
  }
  else{
    num=N/max(H,W);
  }
  cout << num <<endl;
}