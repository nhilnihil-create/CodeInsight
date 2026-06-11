#include<bits/stdc++.h>
using namespace std;

int main(){
  int k,x;
  cin >> k >> x;
  for(int i=max(-1000000,x-k+1);i<min(x+k,1000000);i++){
    cout << i;
    if(i!=x+k-1&&i!=1000000)
      cout << " ";
  }
  cout << endl;
  return 0;
}