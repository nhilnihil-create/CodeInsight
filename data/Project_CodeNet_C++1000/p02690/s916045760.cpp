#include<bits/stdc++.h>
using namespace std;

int main(){
  long long X;
  cin >> X;
  for(long long i=-200;i<201;i++){
    for(long long j=-200;j<201;j++){
      if(i*i*i*i*i-j*j*j*j*j==X){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
}
  