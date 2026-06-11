#include <iostream>
#include <vector>
using namespace std;

int main(){
  int M,D;
  cin>>M>>D;
  int i = 0;//一の位
  double j = 0;
  int k = 0;//合計
  int l = 0;//10の位
  for(int m = 0;m <= M;m++){
    for(int d = 0;d <= D;d++){
      i = d % 10;
      j = d / 10;
      l = j;
      if(i >= 2 && l >= 2 && i * l == m){
        k++;
      }
      i = 0;
      j = 0;
      l = 0;
    }
  }
  cout<<k<<endl;
}