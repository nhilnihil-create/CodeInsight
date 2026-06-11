#include <iostream>
using namespace std;
int main(){
  int h,w,a,b;
  cin>>h>>w>>a>>b;
  if(a==0||b==0){
    if(a==0&&b==0){
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
          cout<<0;
        }
        cout<<endl;
      }
    }else if(a==0){
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
          if(i<b){
            cout<<0;
          }else{
            cout<<1;
          }
        }
        cout<<endl;
      }
    }else{
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
          if(j<a){
            cout<<0;
          }else{
            cout<<1;
          }
        }
        cout<<endl;
      }
    }
  }else{
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(i<b&&j<a){
          cout<<0;
        }else if(i<b){
          cout<<1;
        }else if(j<a){
          cout<<1;
        }else{
          cout<<0;
        }
      }
      cout<<endl;
    }
  }
  return 0;
}
