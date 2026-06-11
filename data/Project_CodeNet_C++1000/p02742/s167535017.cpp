#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {

  long long H,W;
  cin >> H >> W;
  
  int h=H%2;
  int w=W%2;
  
  if(H==1||W==1){
    cout<<1<<endl;
  }
  else{
    cout<<(H*W+1)/2<<endl;
  }
}