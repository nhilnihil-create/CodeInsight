#include<bits/stdc++.h>
using namespace std;

int main(){
  int M,D,count=0;
  cin >> M >> D;
  for(int i=0;i<M;i++){
    for(int j=0;j<D;j++){
      int D1=(j+1)%10;
      int D10=(j+1)/10;
      if(D1>=2 && D10>=2 && D1*D10==i+1){
        count++;
      }
    }
  }
  cout << count << endl;
}