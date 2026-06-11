#include<iostream>
using namespace std;
int main(){
  int a;
  int b;
  int c;
  cin>>a;
  cin>>b;
  cin>>c;
  if(a==b & b!=c){
    cout<<"Yes"<<endl;
  }
  else if(a==c & b!=c){
    cout<<"Yes"<<endl;
  }
  else if(b==c & a!=c){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}