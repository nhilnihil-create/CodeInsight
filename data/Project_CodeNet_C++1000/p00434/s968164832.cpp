#include<iostream>
using namespace std;

int main(){
  int map[30];
  for(int i = 0 ; i < 30; i++){
    map[i]=0;
  }
  for(int i =0 ; i < 28; i++){
    int index ;
    cin >> index;
    map[index-1] = 1;
  }
  for(int i =0 ; i < 30; i++){
    if(!map[i]){
      cout<<(i+1)<<endl;
    }
  }
}