#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
  while(1){
    int height,weight;
    scanf("%d %d",&height,&weight);
    if(height==0&&weight==0) break;
  for(int i=1;i<=height;i++){
    for(int j=1;j<=weight;j++){
      if((i+j)%2==0){
        cout << '#';
      }else{
        cout << '.';
      }
    }
    cout << '\n';
  }
  cout << '\n';
 }
}