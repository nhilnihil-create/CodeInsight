#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, cnt=0;
  for(int i=0; i<5; i++){
    cin >> x;
    cnt++;
    if(x==0)
      break; 
  }
  cout << cnt << endl;
}

  