#include<iostream>
using namespace std;

int main(){
  int n;
  string str="No";
  cin>>n;
  for(int i=2;i<10;i++){
    if(n%i==0){
      if(n/i<10){
        str="Yes";
      }
    }
  }
  if(n==1){str="Yes";}
  cout<<str;
  return 0;
}
