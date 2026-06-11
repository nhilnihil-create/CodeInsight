#include <iostream>
using namespace std;

int main(){
  char c;
  cin>>c;
  
  if('Z'-c<0){
    cout<<'a';
  }else
    cout<<'A';
}
