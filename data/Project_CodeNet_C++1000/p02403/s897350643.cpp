#include<iostream>
using namespace std;
int main(){
int h,w;
while(true){
cin>>h>>w;
if(h==0&&w==0){
  break;
}else{
  for(int i=0;i<h;i++){
    for(int i=0;i<w;i++){
     cout <<"#";
    }
    cout <<endl;
  }
  cout <<endl;
}
}
return 0;
}