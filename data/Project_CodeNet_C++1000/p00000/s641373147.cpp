#include <iostream>
int main(){
  for(int y=1;y<=9;y++){
    for(int x=1;x<=9;x++){
      using std::cout;
      using std::endl;
      cout<<y<<'x'<<x<<'='<<y*x<<endl;
    }
  }
  return 0;
}