#include <iostream>

using namespace std;
void printRect(int H,int W){
  for(int i = 0; i < H ; i++){
    for(int j = 0; j < W; j++){
      cout<<"#";
    }
    cout<<endl;
  }
}
int main(){
  int h,w;
  cin>>h>>w;
  while(h!=0 || w!=0){
    printRect(h,w);
    cout<<endl;
    cin>>h>>w;
  }
}