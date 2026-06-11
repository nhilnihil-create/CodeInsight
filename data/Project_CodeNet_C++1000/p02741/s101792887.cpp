#include<iostream>
using namespace std;

int main(){
  int k;cin>>k;
  if(k==4||k==6||k==9||k==10||k==14||k==21||k==22||k==25||k==26){
    cout<<2<<endl;
  }else if(k==28||k==30){
    cout<<4<<endl;
  }else if(k==8||k==12||k==18||k==20||k==27){
    cout<<5<<endl;
  }else if(k==16){
    cout<<14<<endl;
  }else if(k==24){
    cout<<15<<endl;
  }else if(k==32){
    cout<<51<<endl;
  }else cout<<1<<endl;
  return 0;
}