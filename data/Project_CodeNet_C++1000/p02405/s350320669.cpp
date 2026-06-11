#include <iostream>

using namespace std;

int h,w;

int main(){
  while(true){
    cin>>h>>w;
    if(h==0||w==0) break;

    for(int i=0;i<h;++i){
      if(i%2==0){
        for(int j=0;j<w;++j){
          if(j%2==0){
            cout<<"#";
          }else{
            cout<<".";
          }
        }
        cout<<endl;
      }else{
        for(int j=0;j<w;++j){
          if(j%2==0){
            cout<<".";
          }else{
            cout<<"#";
          }
        }
        cout<<endl;
      }
    }
    cout<<endl;
  }
}