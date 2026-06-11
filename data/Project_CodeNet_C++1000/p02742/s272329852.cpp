#include <bits/stdc++.h>
using namespace std;

int main(){
  long long H,W;
  cin >>H>>W;
  if(H==1||W==1){
    cout<<1<<endl;
    return 0;
  }
  cout<<setprecision(20)<<(W/2)*(H/2)+(W/2+W%2)*(H/2+H%2)<<endl;
  return 0;
}
